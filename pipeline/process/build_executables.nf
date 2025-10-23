process build_executables {
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

    # on récupère instrType pour savoir si on compile en double, float, int, ou fixedpt
    INSTR_TYPE=$(jq -r '.instrType' ${expe_folder}/params/trainParams.json)

    cd ./armlearn-wrapper/build
    rm -rf *

    # on configure la compilation avec cmake en fonction du type d'instruction
    if [ "$INSTR_TYPE" == "double" ]; then
        CXXFLAGS="-DUSE_DOUBLE" CFLAGS="-DUSE_DOUBLE" cmake ..
    elif [ "$INSTR_TYPE" == "float" ]; then
        CXXFLAGS="-DUSE_FLOAT" CFLAGS="-DUSE_FLOAT" cmake ..
    elif [ "$INSTR_TYPE" == "int" ]; then
        CXXFLAGS="-DUSE_INT" CFLAGS="-DUSE_INT" cmake ..
    elif [ "$INSTR_TYPE" == "fixedpt" ]; then
        CXXFLAGS="-DUSE_FIXEDPT" CFLAGS="-DUSE_FIXEDPT" cmake ..
    else
        echo "Unknown instrType: $INSTR_TYPE"
        exit 1
    fi

    cmake --build . --target armCodeGen
    cd ../..
    # on déplace l'exécutable dans le dossier de sortie
    mv ./armlearn-wrapper/build/armCodeGen ${expe_folder}/outLogs/CodeGen/.
    """
}