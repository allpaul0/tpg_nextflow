
process inference_simulator {
    cpus = 1
    memory = '2 GB'
    time = '1h'

    input:
    path expe_json

    output:
    path "${expe_json.parent.parent}/inference_results"   // store all results here

    script:
    """
    echo "Running inference with ${expe_json}"

    # read JSON to extract parameters
    tpg=\$(jq -r '.tpg' ${expe_json})
    uarch=\$(jq -r '.uarch' ${expe_json})
    isa=\$(jq -r '.isa' ${expe_json})
    abi=\$(jq -r '.abi' ${expe_json})
    dtype=\$(jq -r '.dtype' ${expe_json} | tr '[:lower:]' '[:upper:]')

    # define results folder
    res_dir="${expe_json.parent.parent}/inference_results"
    mkdir -p \$res_dir

    apptainer exec --overlay ${params.projectRoot}/overlay.img \
        --bind ${expe_json.parent}:/params/ \
        --bind \$res_dir:/outLogs/ \
        ${params.projectRoot}/containers/x-heep.sif \
        /bin/bash -c "cd /x-heep && ./scripts/automatic-generation_simulator/generate-mcu.sh ${simulator_config} && \
        ./scripts/automatic-simulation/simulation.sh ${simulator_config} ${isa} ${abi} ${dtype} && \
        mv experimentations/simulations/${simulator}_${isa}_${abi}_${dtype}.json /outLogs/."
    """
}