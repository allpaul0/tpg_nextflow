#!/usr/bin/env nextflow
include { inference_simulator } from "./process/inference_simulator.nf"
include { generate_TPG_ISA_UARCH_configs } from "./process/generate_TPG_ISA_UARCH_configs.nf"

nextflow.enable.dsl=2

// This pipeline realizes the inference phase by entering the x-heep container, generating a simulator 
// and simulating the TPG with the required ISA on the Inference Benchmark.

// For each TPG, 
// for each intelligent ISA and microarchitecture combination,
// run the inference benchmark on the simulator.
// Inference latencies are collected, parsed and stored in a CSV file.

workflow {

    // Channel of prepared TPG folders
    def ch_prepared_TPGs = Channel.fromPath("tpg_expe/training_results/*", type: 'dir')//params.prepared_TPGs_path

    if (params.mini_config != 0) {
        println "Using mini configuration for testing purposes..."
        ch_prepared_TPGs = ch_prepared_TPGs.take(params.mini_config)
    }

    // Generate JSON configs using Python
    def ch_configs = generate_TPG_ISA_UARCH_configs(ch_prepared_TPGs)

    def takeFirstOnly = true  // or false

    // For each TPG, flatten JSON config files
    def ch_TPG_JSONs = ch_configs
        .flatMap { tpg_folder ->
            def config = file("${tpg_folder}/inference/configs")
            def jsonFiles = config.listFiles()
                                .findAll { it.name.endsWith(".json") }

            if (takeFirstOnly && jsonFiles) {
                jsonFiles = [ jsonFiles[0] ]
            }

            jsonFiles.collect { jsonFile -> tuple(tpg_folder, jsonFile) }
    }

    // display the JSONs found
    // ch_TPG_JSONs.view { t -> "Found TPG JSON config: ${t[1]} in folder ${t[0]}" }

    // Run inference simulator for each JSON config
    inference_simulator(ch_TPG_JSONs)
}