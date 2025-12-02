process parse_results {
    cpus = 1
    memory = '1 GB'
    time = '1m 30s'

    input:
    path training_results

    output:
    path "results.csv"

    publishDir "${params.outdir}/parsed_results", mode: 'copy'

    // This script aggregates training results from multiple experiment folders into a single CSV file. 
    script:
    """
    python3 ${projectDir}/scripts/parse_results.py ${training_results}
    """
}