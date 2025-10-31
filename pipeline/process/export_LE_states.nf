process export_LE_states {
    cpus = 1
    memory = '1 GB'
    time = '5m'
        
    input:
    path expe_folder

    output:
    path expe_folder

    publishDir "${params.outdir}/LE_states", mode: 'copy'

    // This script generates the Learning Environment initial states for inference.  
    // the number of graph traversal differs for each TPG, therefore its a per TPG process 
    script:
    """
    echo "Exporting LE states for TPG model in ${expe_folder}"

    # run the exportLEstates in the Singularity container
    apptainer exec --bind ${expe_folder}/params:/params/ --bind ${expe_folder}/outLogs:/outLogs/ ${params.projectRoot}/containers/gegelati-armlearn.sif /bin/bash -c "cd / && ./armlearn-wrapper/build/exportLEstates"
    """
}