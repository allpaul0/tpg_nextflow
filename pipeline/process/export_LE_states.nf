process export_LE_states {
    cpus 1
    memory '1 GB'
    time '5m'

    publishDir "${params.outdir}/LE_states", mode: 'copy'

    input:
    path tpg_folder

    output:
    path tpg_folder

    // This script generates the Learning Environment initial states for inference.  
    // the number of graph traversal differs for each TPG, therefore its a per TPG process 
    script:
    """
    tpg_folder=\$(realpath ${tpg_folder})

    echo "Exporting LE states for TPG model in ${tpg_folder}"
    bash ${params.projectRoot}/pipeline/scripts/export_LE_states.sh \
        \$tpg_folder ${params.projectRoot}
    """
}