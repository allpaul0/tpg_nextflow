process train_tpg {
    executor = 'slurm'
    memory = '10 GB'
    cpus = 128
    time = '125m'

    input:
    path expe_folder

    output:
    path expe_folder

    publishDir "${params.outdir}/training_results", mode: 'copy'

    script:
    """
    echo "Training TPG model with ${expe_folder}"
    apptainer exec --bind ${expe_folder}/params:/params/ --bind ${expe_folder}/outLogs:/outLogs/ ${params.projectRoot}/containers/gegelati-arm.sif /bin/bash -c "cd / && ./armlearn-wrapper/build/armGegelati"
    """
}