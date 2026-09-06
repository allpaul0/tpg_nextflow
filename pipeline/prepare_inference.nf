#!/usr/bin/env nextflow

nextflow.enable.dsl=2

include { generate_code } from "./process/generate_code.nf"
include { export_LE_states } from "./process/export_LE_states.nf"
include { build_executables } from "./process/build_executables.nf"

// This pipeline prepares the inference phase by generating code, exporting LE states and building executables

// A TPG dir is a training-result dir: it holds the training params and the outLogs tree.
def isTpgDir( d ) {
    d.resolve("params/trainParams.json").exists() && d.resolve("outLogs").exists()
}

workflow {

    if( !params.projectRoot ) {
        error "projectRoot is not defined in the configuration nor given in the command line."
    }

    def mini = params.mini_config.toInteger()

    // Flags filled in while the channel is built, so an empty channel can be
    // reported with the reason that actually caused it.
    def stats = [ tpg: 0, codegen_done: 0, fully_done: 0 ]

    // params.trained_TPGs_path may match either TPG dirs directly, or container dirs
    // holding TPG dirs (e.g. '.../training_results/*' vs '.../training_results').
    // Detecting which case we are in matters: the outLogs/codegen probes below must be
    // resolved against the TPG dir, never against its parent.
    // Normalize both layouts to a flat channel of TPG dirs.
    def ch_tpg_dirs = Channel.fromPath(params.trained_TPGs_path, type: 'dir', checkIfExists: true)
        .flatMap { dir ->
            if( isTpgDir(dir) ) {
                log.debug "TPG dir: ${dir}"
                return [ dir ]
            }
            // not a TPG dir: look one level down for TPG dirs
            def children = dir.listFiles().findAll { it.isDirectory() && isTpgDir(it) }
            if( children ) {
                log.info "Container dir: ${dir} -> ${children.size()} TPG dir(s)"
                return children
            }
            log.warn "Skipping dir (neither a TPG dir nor a container of TPG dirs): ${dir}"
            return []
        }

    // For each TPG dir, detect which of the three codegen outputs are missing.
    // When the three of them are already there, the dir is not necessarily finished:
    // the LE-state export (outLogs/precalcul) may still be missing, in which case the
    // dir must skip generate_code and go directly to export_LE_states.
    def ch_status = ch_tpg_dirs
        .map { dir ->
            stats.tpg = stats.tpg + 1
            def need_default   = !dir.resolve("outLogs/codegen").exists()
            def need_teams     = !dir.resolve("outLogs/codegen_TeamsInstrumented").exists()
            def need_dispatch  = !dir.resolve("outLogs/codegen_DispatchInstrumented_TeamsInstrumented").exists()
            def need_precalcul = !dir.resolve("outLogs/precalcul").exists()

            if( !(need_default || need_teams || need_dispatch) ) {
                stats.codegen_done = stats.codegen_done + 1
                if( !need_precalcul ) {
                    stats.fully_done = stats.fully_done + 1
                    log.debug "Nothing to do (codegen + precalcul present): ${dir}"
                }
                else {
                    log.info "Codegen complete, precalcul missing -> export only: ${dir}"
                }
            }
            tuple(dir, need_default, need_teams, need_dispatch, need_precalcul)
        }
        // keep only dirs that still need at least one codegen variant or the export
        .filter { dir, need_default, need_teams, need_dispatch, need_precalcul ->
            need_default || need_teams || need_dispatch || need_precalcul
        }

    if (mini > 0)
    {
        println "mini-config taken"
        ch_status = ch_status.take(mini)
    }

    // safety check to ensure we have some training directories to work with after
    // filtering and taking the mini_config -- report which of the two causes it was
    ch_status.ifEmpty {
        if( stats.tpg == 0 )
            error "No TPG directory found under trained_TPGs_path. Check the paths in the config."
        if( stats.fully_done == stats.tpg )
            error "Nothing to do: all ${stats.tpg} TPG dir(s) already have the three codegen folders (codegen, codegen_TeamsInstrumented, codegen_DispatchInstrumented_TeamsInstrumented) and the precalcul folder. Remove them with utils/clean_tpgs.sh to regenerate."
        error "No training directories found after filtering/take(). Check mini_config and paths."
    }

    // dirs missing at least one codegen variant: run generate_code
    ch_to_generate = ch_status
        .filter { dir, need_default, need_teams, need_dispatch, need_precalcul ->
            need_default || need_teams || need_dispatch
        }
        .map { dir, need_default, need_teams, need_dispatch, need_precalcul ->
            tuple(dir, need_default, need_teams, need_dispatch)
        }

    // dirs with the three codegen folders but no precalcul: skip generate_code
    ch_export_only = ch_status
        .filter { dir, need_default, need_teams, need_dispatch, need_precalcul ->
            !(need_default || need_teams || need_dispatch) && need_precalcul
        }
        .map { dir, need_default, need_teams, need_dispatch, need_precalcul -> dir }

    generated_codes = generate_code(ch_to_generate)

    // skip LE-state export where the precalcul output already exists
    // (re-checked here because generate_code may have produced it)
    ch_to_export = generated_codes
        .mix(ch_export_only)
        .filter { tpg_folder ->
            !tpg_folder.resolve("outLogs/precalcul").exists()
        }

    exported_LE_states = export_LE_states(ch_to_export)

    // unused for now, we build on X-HEEP using the RISCV compiler toolchain
    // can be set to compile for x86 using the right compiler
    // built_executables = build_executables(ch_trained_TPGs)
}
