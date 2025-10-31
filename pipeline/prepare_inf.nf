#!/usr/bin/env nextflow
include { generate_code } from "./process/generate_code.nf"
include { export_LE_states } from "./process/export_LE_states.nf"
include { build_executables } from "./process/build_executables.nf"

nextflow.enable.dsl=2

// This pipeline prepares the inference phase by generating code, exporting LE states and building executables

workflow {
    def ch_trained_TPGs = Channel.fromPath(params.trained_TPGs_path, type: 'dir') //params.trained_TPGs_path

    generated_codes = generate_code(ch_trained_TPGs)

    exported_LE_states = export_LE_states(ch_trained_TPGs)
    
    //built_executables = build_executables(generated_codes, exported_LE_states)
}