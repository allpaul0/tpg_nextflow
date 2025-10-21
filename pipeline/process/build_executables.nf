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
    
    cp -r /armlearn-wrapper ./ #on copie le dossier armlearn-wrapper puisqu'on en modifie le contenu
    # on copie les fichiers générés par generate_code dans le dossier src/codeGen
    cp ${expe_folder}/outLogs/CodeGen/codeGenArmlearn_program.* armlearn-wrapper/src/codeGen
    cp ${expe_folder}/outLogs/CodeGen/codeGenArmlearn.* armlearn-wrapper/src/codeGen
    cd ./armlearn-wrapper/build
    rm -rf *
    cmake ..
    cmake --build . --target armCodeGen
    cd ../..
    # on déplace l'exécutable dans le dossier de sortie
    mv ./armlearn-wrapper/build/armCodeGen ${expe_folder}/outLogs/CodeGen/.
    """
}