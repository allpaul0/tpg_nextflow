process train_tpg {
    executor = 'slurm'
    memory = '10 GB'
    cpus = params.training_cores
    time = "${params.training_time + 240} s" // Add 4 minutes for safety, as training is terminated between generations.

    input:
    path expe_folder

    output:
    path expe_folder

    publishDir "${params.outdir}/training_results", mode: 'copy'

    // The training is run inside the container, with the params and outLogs folders binded to the container.
    script:
    """
    echo "Training TPG model with ${expe_folder}"
    apptainer exec --bind ${expe_folder}/params:/params/ --bind ${expe_folder}/outLogs:/outLogs/ ${params.projectRoot}/containers/gegelati-armlearn.sif /bin/bash -c "cd / && ./armlearn-wrapper/build/armGegelati"
    """
}