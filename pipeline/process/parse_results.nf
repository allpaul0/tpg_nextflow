process parse_results {
    cpus 1
    memory '1 GB'
    time '10m'
    container "${params.projectRoot}/containers/nextflow-insa.sif"

    publishDir "${params.outdir}/accuracy_results", mode: 'copy'

    input:
    path training_results

    output:
    path "results.csv"

    // This script aggregates training results from multiple experiment folders into a single CSV file. 
    script:
    """
    python3 ${projectDir}/scripts/parse_results.py ${training_results}
    """
}