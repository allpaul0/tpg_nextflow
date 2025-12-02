process generate_configs {
    cpus = 1
    memory = '1 GB'
    time = '5m'
    
    input:
    val config
    path hyperparameters
    val use_local_params

    output:
    path "*"

    // This script generates configuration files for TPG training based on isntruction_set and data_types. 
    script:
    """
    echo "Generate_configs.nf: Generating configuration with configs: ${config}, hyperparameters: ${hyperparameters}, use_local_params: ${use_local_params}"
    python3 ${projectDir}/scripts/generate_configs.py \
        '${groovy.json.JsonOutput.toJson(config)}' \
        ${params.training_time} \
        ${params.nb_generations} \
        ${params.training_cores} \
        ${hyperparameters} \
        ${use_local_params} 
    """
}