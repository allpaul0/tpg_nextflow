#!/usr/bin/env nextflow
include { generate_configs } from "./process/generate_configs.nf"
include { train_tpg } from "./process/train_tpg.nf"

nextflow.enable.dsl=2

workflow {
    def ch_types = Channel.from(params.types)
    def ch_seeds = Channel.from(0..<params.nb_seeds)
    def ch_instruction_sets = Channel.from(params.instruction_sets)

    if (params.mini_config) {
        ch_types = ch_types.take(2)
        ch_seeds = ch_seeds.take(2)
        ch_instruction_sets = ch_instruction_sets.take(2)
    }

    ch_parameters = ch_seeds
        .combine(ch_instruction_sets)
        .combine(ch_types)
        .map { seed, instruction_set, type -> instruction_set + [seed: seed, type: type] }
        

    configs = generate_configs(ch_parameters)

    train_tpg(configs)
}