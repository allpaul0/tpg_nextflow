process generate_code {
    cpus = 1
    memory = '1 GB'
    time = '5m 30s'
    
    input:
    path expe_folder

    output:
    path expe_folder

    publishDir "${params.outdir}/codegen_results", mode: 'copy'

    script:
    """
    echo "Generating code for TPG model in ${expe_folder}"
    
    # runs sed in-place to update the JSON value for "testPath" in the trainParams.json file to point to the out_best.dot file
    sed -i 's/"testPath": "outLogs"/"testPath": ".\\/outLogs\\/out_best.dot"/' ./${expe_folder}/params/trainParams.json
    
    # run the code generation inside the Singularity container
    apptainer exec --bind ${expe_folder}/params:/params/ --bind ${expe_folder}/outLogs:/outLogs/ ${params.projectRoot}/containers/gegelati-armlearn.sif /bin/bash -c "cd / && ./armlearn-wrapper/build/armGraphPruner"

    # Patch generated code to use correct data types
    ./patch_generated_code.sh "${expe_folder}"
    """
}