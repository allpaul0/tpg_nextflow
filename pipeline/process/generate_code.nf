process generate_code {
    cpus 1
    memory '1 GB'
    time '5m 30s'

    // publishDir "${params.outdir}/codegen_results", mode: 'copy'

    tag "${tpg_folder.name}"

    input:
    tuple path(tpg_folder), val(need_default), val(need_teams), val(need_dispatch)

    output:
    path tpg_folder

    script:
    """
    tpg_folder=\$(realpath ${tpg_folder})
    
    echo "Generating code for TPG model in ${tpg_folder}"
    bash ${params.projectRoot}/pipeline/scripts/generate_code.sh \
        \$tpg_folder ${params.projectRoot} ${need_default} ${need_teams} ${need_dispatch}
    """
}