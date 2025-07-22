process generate_code {
    executor = 'slurm'
    cpus = 1
    memory = '1 GB'
    time = '2m 30s'
    
    input:
    path expe_folder

    output:
    path expe_folder

    publishDir "${params.outdir}/codegen_results", mode: 'copy'

    script:
    """
    sed -i 's/"testPath": "outLogs"/"testPath": ".\\/outLogs\\/out_best.dot"/' ./${expe_folder}/params/trainParams.json
    apptainer exec --bind ${expe_folder}/params:/params/ --bind ${expe_folder}/outLogs:/outLogs/ ${params.projectRoot}/containers/gegelati-arm.sif /bin/bash -c "cd / && ./armlearn-wrapper/build/armGraphPruner"
    """
}