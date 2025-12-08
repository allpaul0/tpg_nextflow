process find_missing_inference_results_nf {
    cpus = 1
    memory = '1 GB'
    time = '5min'

    input:
    path tpg_folder

    output:
    path 'missing.txt'

    script:
    """
    python3 ${params.projectRoot}/pipeline/scripts/find_missing_inference_results.py ${tpg_folder} > missing.txt
    """
}