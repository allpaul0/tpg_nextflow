process inference_simulator {
    cpus = 1
    memory = '1 GB'
    time = '1h'

    input:
    tuple path(tpg_folder), path(expe_json)

    // output: literal folder path relative to the JSON
    output:
    path("${tpg_folder}/inference/results")

    script:
    """
    expe_json=\$(realpath ${expe_json})
    tpg_folder=\$(realpath ${tpg_folder})

    echo "Running inference simulation with config \$expe_json"
    echo "TPG folder: \$tpg_folder"
    bash ${params.projectRoot}/pipeline/scripts/simulation.sh \$expe_json \$tpg_folder ${params.projectRoot}
    """
}

