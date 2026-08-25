#!/usr/bin/env nextflow

nextflow.enable.dsl=2

include { inference_simulator }             from "./process/inference_simulator.nf"
include { generate_TPG_ISA_UARCH_configs }  from "./process/generate_TPG_ISA_UARCH_configs.nf"
include { detect_inference_work }           from "./process/detect_inference_work.nf"

// This pipeline realizes the inference phase by entering the x-heep container, generating a simulator
// and simulating the TPG with the required ISA on the Inference Benchmark.
//
// For each TPG:
//     For each ISA/microarchitecture config:
//         Detect which apps (default / teams / dispatch) are still missing, and run only those.
//         as inference benchmark on the simulator 
//         Inference latencies are collected, parsed and stored in a CSV file and fused
//         into latencies.json 
//
// Advancement detection:
//   Step 1 (config generation): generate_TPG_ISA_UARCH_configs skips a TPG whose configs already
//                               exist (unless --force). This is the "was step 1 done?" check.
//   Step 2 (per-app simulation): detect_inference_work inspects results/<tag>/latencies.json keys
//                               and disassembly files, and emits only the apps still to run.

workflow {

    if( !params.projectRoot ) {
        error "projectRoot is not defined in the configuration nor given in the command line."
    }

    // Only set clusterOptions if using a cluster executor
    if (params.executor != 'local') {
        clusterOptions = '--nodes=1 --cpus-per-task=1 --mem=512MB'
    }

    // add a line to check if ${project_root}/containers/x-heep.sif exists and print a warning 
    // if it does not, since the inference_simulator process requires it
    def containerPath = "${params.projectRoot}/containers/x-heep.sif"

    if (!file(containerPath).exists()) {
        error """
        ERROR: The required container ${containerPath} does not exist.

        The inference_simulator process requires this container to run.
        Please build it using the dedicated GitHub repo.
        """
    }

    // Channel of prepared TPG folders
    def ch_prepared_TPGs = Channel.fromPath(params.prepared_TPGs_path, type: 'dir')

    // ---- Step 1: ensure configs exist (skips internally if already complete) ----
    // When resuming we assume configs already exist and skip generation entirely.
    def ch_ready
    if( !params.inference_resume ) {
        // Generate JSON configs using Python
        // JSON config is a mapping: TPG, uarch, isa, abi, dtype, compiler
        // uarch list defines which subgroup to generate configs for e.g. "cv32e40px", "cv32e40px_fpu"
        ch_ready = generate_TPG_ISA_UARCH_configs(ch_prepared_TPGs, params.uarch_list)
    } else {
        println "Resuming: skipping config generation, detecting missing work only..."
        ch_ready = ch_prepared_TPGs
    }

    // ---- Step 2: detect, per TPG, which (config, apps) still need running ----
    def ch_todo = detect_inference_work(ch_ready, params.uarch_list)

    // Parse the TSV work list into (tpg_folder, config_json, apps_csv) tuples.
    // Each line: <absolute_config_path>\t<comma_separated_apps>
    def ch_TPG_JSONs = ch_todo
        .splitText()
        .map { it?.trim() }
        .filter { it }                              // drop blank lines
        .map { line ->
            def parts = line.split('\t')
            def cfg   = file(parts[0])
            def apps  = (parts.size() > 1 && parts[1]) ? parts[1] : 'default,teams,dispatch'
            def tpg_folder = cfg.parent.parent.parent   // configs -> inference -> tpg_folder
            tuple(tpg_folder, cfg, apps)
        }

    def mini = params.mini_config.toInteger()
    if (mini > 0) {
        println "mini_config=${mini}: limiting to ${mini} work item(s), running serially"
        ch_TPG_JSONs = ch_TPG_JSONs.take(mini)
        
        //ch_TPG_JSONs = ch_TPG_JSONs.filter { tpg, cfg, apps ->
        //tpg.name.contains('useInstrTrig-False_useInstrLogExp-False_useInstrLog2Exp2-True_useInstrZmmul-False_useInstrExpensiveArithmetic-False_useInstrComparison-True_seed-4_instrType-fixedpt') &&
        //cfg.name.startsWith('cv32e40x_im1_zba_zbb') && 
        //apps.contains('dispatch')}
    } else {
        println "mini_config=0: running all work items"
    }

    // Debug helpers (uncomment as needed):
    ch_TPG_JSONs.view { t -> "TODO: ${t[1].name} -> apps=[${t[2]}] (tpg ${t[0].name})" }
    ch_TPG_JSONs.count().view { c -> "Total (config, apps) work items: ${c}" }

    // Run inference simulator for the missing apps of each config
    inference_simulator(ch_TPG_JSONs)
}
