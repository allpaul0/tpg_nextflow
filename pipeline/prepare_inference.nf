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

    def ch_trained_TPGs = Channel.fromPath(params.trained_TPGs_path, type: 'dir').filter{ dir ->!dir.resolve("outLogs/codegen").exists()}

    if (mini > 0) 
    {
        // echo hello
        println "hello"
        ch_trained_TPGs = ch_trained_TPGs.take(mini)
    }

    // safety check to ensure we have some training directories to work with after filtering and taking the mini_config
    ch_trained_TPGs.ifEmpty {
        error "No training directories found after filtering/take(). Check mini_config and paths."
    }

    generated_codes = generate_code(ch_trained_TPGs)

    exported_LE_states = export_LE_states(generated_codes)
    
    // unused for now, we build on X-HEEP using the RISCV compiler toolchain
    // can be set to compile for x86 using the right compiler
    // built_executables = build_executables(ch_trained_TPGs)
}