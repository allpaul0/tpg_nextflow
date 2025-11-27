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
    
    # runs sed in-place to update the JSON value for "tpgDotPath" in the trainParams.json file to point to the out_best.dot file
    sed -i 's/"tpgDotPath": "outLogs"/"tpgDotPath": ".\\/outLogs\\/out_best.dot"/' ./${expe_folder}/params/trainParams.json
    
    # run the code generation inside the Singularity container
    apptainer exec --bind ${expe_folder}/params:/params/ --bind ${expe_folder}/outLogs:/outLogs/ ${params.projectRoot}/containers/gegelati-armlearn.sif /bin/bash -c "cd / && cp armlearn-wrapper/params/AllTarget.csv params/. && cp armlearn-wrapper/params/ValidationTrajectories.txt params/. && ./armlearn-wrapper/build/CodeGen"

    # Patch generated code to use correct data types
    bash ${projectDir}/scripts/patch_generated_code.sh "${expe_folder}"
    """
}