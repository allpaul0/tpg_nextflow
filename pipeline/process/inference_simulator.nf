process inference_simulator {
    cpus 1
    memory '512 MB'
    time '2h'

    input:
    tuple path(tpg_folder), path(expe_json), val(apps)

    // output: literal folder path relative to the JSON
    output:
    path("${tpg_folder}/inference/results")

    script:
    // DEV MODE (boolean switch)
    //   params.xheep_dev = true  -> pass the host x-heep checkout as simulation.sh's
    //                               5th arg, which binds it at /opt/x-heep and runs
    //                               everything from there instead of the container's
    //                               baked-in /x-heep.
    //   params.xheep_dev = false -> 5th arg omitted entirely; production behaviour.
    //
    // Which checkout gets used is params.xheep_dev_path, defaulting to the x-heep
    // tree already living under projectRoot (the same one the simulators come from).
    //
    // .toString().toBoolean() so that both `params.xheep_dev = true` in the config
    // and `--xheep_dev true` on the command line work (the CLI passes a String).
    def dev_on   = params.xheep_dev?.toString()?.toBoolean() ?: false
    def dev_path = params.xheep_dev_path ?: "${params.projectRoot}/x-heep"
    def dev_arg  = dev_on ? " ${dev_path}" : ""
    """
    expe_json=\$(realpath ${expe_json})
    tpg_folder=\$(realpath ${tpg_folder})

    echo "Running inference simulation with config \$expe_json"
    echo "TPG folder: \$tpg_folder"
    echo "Apps to run: ${apps}"
    ${dev_on ? "echo 'DEV MODE: using x-heep checkout ${dev_path}'" : "true"}

    bash ${params.projectRoot}/pipeline/scripts/simulation.sh \\
        \$expe_json \$tpg_folder ${params.projectRoot} ${apps}${dev_arg}
    """
}

