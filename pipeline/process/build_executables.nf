process build_executables {
    container 'gegelati-armlearn.sif'
    cpus 1
    memory '1 GB'
    time '4m 30s'

    publishDir "${params.outdir}/executables", mode: 'copy'
    
    input:
    path expe_folder

    output:
    path expe_folder


    script:
  
    """
    scripts/build_executables.sh "${expe_folder}"
    """
}