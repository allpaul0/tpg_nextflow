#!/usr/bin/env nextflow

nextflow.enable.dsl=2

include { inference_simulator } from "./process/inference_simulator.nf"
include { generate_TPG_ISA_UARCH_configs } from "./process/generate_TPG_ISA_UARCH_configs.nf"
include { find_missing_inference_results_nf } from "./process/find_missing_inference_results_nf.nf"

// This pipeline realizes the inference phase by entering the x-heep container, generating a simulator 
// and simulating the TPG with the required ISA on the Inference Benchmark.

// For each TPG, 
// for each intelligent ISA and microarchitecture combination,
// run the inference benchmark on the simulator.
// Inference latencies are collected, parsed and stored in a CSV file.

workflow {

    if( !params.inference_resume ) {

        // Channel of prepared TPG folders
        def ch_prepared_TPGs = Channel.fromPath(params.prepared_TPGs_path, type: 'dir')

        // Generate JSON configs using Python
        def ch_configs = generate_TPG_ISA_UARCH_configs(ch_prepared_TPGs)

        def takeFirstOnly = false  // or false

        // For each TPG, flatten JSON config files
        ch_TPG_JSONs = ch_configs
            .flatMap { tpg_folder ->
                def config = file("${tpg_folder}/inference/configs")
                def jsonFiles = config.listFiles()
                                    .findAll { it.name.endsWith(".json") }

                if (takeFirstOnly && jsonFiles) {
                    jsonFiles = [ jsonFiles[0] ]
                }

                jsonFiles.collect { jsonFile -> tuple(tpg_folder, jsonFile) }
        }

    } else {

        //print hello
        println "Resuming inference phase by finding missing inference results..."
    
        // Read missing.txt and convert lines to Files
        def ch_tpg_expe = Channel.fromPath(params.tpg_expe, type: 'dir')

        missing_files_ch = find_missing_inference_results_nf(ch_tpg_expe)
        
        ch_TPG_JSONs = missing_files_ch
            .splitText()
            .map { line ->
                // ensure whitespace trimmed and skip empty lines
                line = line?.trim()
                if (!line) return null
                def cfg = file(line)
                def tpg_folder = cfg.parent.parent.parent
                tuple(tpg_folder, cfg)
            }
            .filter { it != null }     // remove any nulls produced by blank lines
    }

    if (params.mini_config != 0) {
        ch_TPG_JSONs = ch_TPG_JSONs.take(params.mini_config)
    }

    // display the JSONs found
    ch_TPG_JSONs.view { t -> "Found TPG JSON config: ${t[1]} in folder ${t[0]}" }
    // count the number of JSON configs to process
    ch_TPG_JSONs.count().view { c -> "Total number of TPG JSON configs to process: ${c}" }

    // Run inference simulator for each JSON config
    inference_simulator(ch_TPG_JSONs)
}