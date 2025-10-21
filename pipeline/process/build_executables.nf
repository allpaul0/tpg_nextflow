process build_executables {
    executor = 'slurm'
    container = 'gegelati-armlearn.sif'
    cpus = 1
    memory = '1 GB'
    time = '4m 30s'
    
    input:
    path expe_folder

    output:
    path expe_folder

    publishDir "${params.outdir}/executables", mode: 'copy'

    script:
    """
    echo "Building code for TPG model in ${expe_folder}"

    
    cp -r /armlearn-wrapper ./
    cp ${expe_folder}/outLogs/codeGen/* armlearn-wrapper/src/codeGen
    cd ./armlearn-wrapper/build
    rm -rf *
    cmake ..
    cmake --build . --target armCodeGen

    """
}