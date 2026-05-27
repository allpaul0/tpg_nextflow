process generate_code {
    cpus 1
    memory '1 GB'
    time '5m 30s'

    publishDir "${params.outdir}/codegen_results", mode: 'copy'

    input:
    path tpg_folder

    output:
    path tpg_folder

    script:
    """
    tpg_folder=\$(realpath ${tpg_folder})
    
    echo "Generating code for TPG model in ${tpg_folder}"
    bash ${params.projectRoot}/pipeline/scripts/generate_code.sh \
        \$tpg_folder ${params.projectRoot}
    """
}