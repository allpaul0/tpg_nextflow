#!/usr/bin/env nextflow

nextflow.enable.dsl=2

include { generate_code } from "./process/generate_code.nf"
include { export_LE_states } from "./process/export_LE_states.nf"
include { build_executables } from "./process/build_executables.nf"

// This pipeline prepares the inference phase by generating code, exporting LE states and building executables

workflow {

    if( !params.projectRoot ) {
        error "projectRoot is not defined in the configuration nor given in the command line."
    }

    def mini = params.mini_config.toInteger()

    // For each training dir, detect which of the three codegen outputs are missing,
    // and carry that per-item alongside the directory.
    def ch_trained_TPGs = Channel.fromPath(params.trained_TPGs_path, type: 'dir')
        .map { dir ->
            def need_default  = !dir.resolve("outLogs/codegen").exists()
            def need_teams    = !dir.resolve("outLogs/codegen_TeamsInstrumented").exists()
            def need_dispatch = !dir.resolve("outLogs/codegen_DispatchInstrumented_TeamsInstrumented").exists()
            tuple(dir, need_default, need_teams, need_dispatch)
        }
        // keep only dirs that still need at least one codegen variant
        .filter { dir, need_default, need_teams, need_dispatch ->
            need_default || need_teams || need_dispatch
        }

    if (mini > 0) 
    {
        println "mini-config taken"
        ch_trained_TPGs = ch_trained_TPGs.take(mini)
    }

    // safety check to ensure we have some training directories to work with after filtering and taking the mini_config
    ch_trained_TPGs.ifEmpty {
        error "No training directories found after filtering/take(). Check mini_config and paths."
    }

    generated_codes = generate_code(ch_trained_TPGs)

    // skip LE-state export where the precalcul output already exists
    ch_to_export = generated_codes.filter { tpg_folder ->
        !tpg_folder.resolve("outLogs/precalcul").exists()
    }

    exported_LE_states = export_LE_states(ch_to_export)
    
    // unused for now, we build on X-HEEP using the RISCV compiler toolchain
    // can be set to compile for x86 using the right compiler
    // built_executables = build_executables(ch_trained_TPGs)
}