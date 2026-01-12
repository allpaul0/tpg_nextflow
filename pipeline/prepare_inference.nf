#!/usr/bin/env nextflow
include { generate_code } from "./process/generate_code.nf"
include { export_LE_states } from "./process/export_LE_states.nf"
include { build_executables } from "./process/build_executables.nf"

nextflow.enable.dsl=2

// This pipeline prepares the inference phase by generating code, exporting LE states and building executables

workflow {
    def ch_trained_TPGs = Channel.fromPath(params.trained_TPGs_path, type: 'dir')

    if (params.mini_config != 0) {
        ch_trained_TPGs = ch_trained_TPGs.take(params.mini_config)
    }
    //.filter{ dir ->dir.resolve("outLogs/codegen").exists()}

    //generated_codes = generate_code(ch_trained_TPGs)

    exported_LE_states = export_LE_states(ch_trained_TPGs)
    
    //built_executables = build_executables(ch_trained_TPGs)
}