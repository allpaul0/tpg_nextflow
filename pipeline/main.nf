#!/usr/bin/env nextflow
include { generate_configs } from "./process/generate_configs.nf"

nextflow.enable.dsl=2

workflow {
    ch_instruction_sets =
        channel.from(params.instruction_sets)
        .flatten()

    generate_configs(ch_instruction_sets)
}