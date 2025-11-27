#!/usr/bin/env nextflow
include { inference_simulator } from "./process/inference_simulator.nf"

nextflow.enable.dsl=2

// This pipeline realizes the inference phase by entering the x-heep container, generating a simulator 
// and simulating the TPG with the required ISA on the Inference Benchmark.

// For each TPG, 
// for each intelligent ISA and microarchitecture combination,
// run the inference benchmark on the simulator.
// Inference latencies are collected, parsed and stored in a CSV file.

workflow {

    // Channel of prepared TPG folders
    def ch_prepared_TPGs = Channel.fromPath(params.prepared_TPGs_path, type: 'dir')

    // For each TPG, flatten JSON config files
    def ch_TPG_JSONs = ch_prepared_TPGs
        .flatMap { tpg_folder ->
            def config_dir = file("${tpg_folder}/inference_experimentations/configs")
            config_dir.listFiles().findAll { it.name.endsWith(".json") }
        }
    
    // display the JSONs found
    ch_TPG_JSONs.view { "Found TPG JSON config: ${it}" }

    // Run inference simulator for each JSON config
    inference_simulator(ch_TPG_JSONs)
}