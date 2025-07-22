#!/usr/bin/env nextflow
include { generate_configs } from "./process/generate_configs.nf"
include { train_tpg } from "./process/train_tpg.nf"
include { generate_code } from "./process/generate_code.nf"

nextflow.enable.dsl=2

workflow {
    def ch_types = Channel.from(params.types)
    def ch_seeds = Channel.from(0..<params.nb_seeds)
    def ch_instruction_sets = Channel.from(params.instruction_sets)

    if (params.mini_config) {
        ch_types = ch_types.take(params.mini_config)
        ch_seeds = ch_seeds.take(params.mini_config)
        ch_instruction_sets = ch_instruction_sets.take(params.mini_config)
    }

    ch_parameters = ch_seeds
        .combine(ch_instruction_sets)
        .combine(ch_types)
        .map { seed, instruction_set, type -> instruction_set + [seed: seed, type: type] }
        

    configs = generate_configs(ch_parameters)

    trained_TPGs = train_tpg(configs)

    generate_code(trained_TPGs)
}