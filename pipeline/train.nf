#!/usr/bin/env nextflow

nextflow.enable.dsl=2

include { generate_configs } from "./process/generate_configs.nf"
include { train_tpg } from "./process/train_tpg.nf"
include { parse_results } from "./process/parse_results.nf"

// This pipeline trains TPGs based on various configurations and parses the results

workflow {
    
    if( !params.projectRoot ) {
        error "projectRoot is not defined in the configuration nor given in the command line."
    }

    def ch_data_types = Channel.from(params.data_types)
    def nb_seeds = params.nb_seeds.toInteger()
    def ch_seeds = Channel.from(10..<(10 + nb_seeds))
    def ch_instruction_sets = Channel.from(params.instruction_sets)
    def ch_hyperparams = Channel.value(file("./pipeline/parameters/local_params.json"))
    use_local_params = false

    def mini = params.mini_config.toInteger()

    if (mini != 0) {
        println "Using mini configuration for testing purposes..."
        ch_data_types = ch_data_types.take(mini)
        ch_seeds = ch_seeds.take(mini)
        ch_instruction_sets = ch_instruction_sets.take(mini)
        use_local_params = true
    }

    ch_configs = ch_seeds
        .combine(ch_instruction_sets)
        .combine(ch_data_types)
        .map { seed, instruction_set, type -> instruction_set + [seed: seed, instrType: type] }
        
    ch_configs.view { config -> "CONFIG: ${config}" }

    configs = generate_configs(ch_configs, ch_hyperparams, use_local_params)

    trained_TPGs = train_tpg(configs)

    all_trained_TPGs = trained_TPGs.collect()

    parse_results(all_trained_TPGs)
}