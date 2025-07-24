process generate_code {
    executor = 'slurm'
    cpus = 1
    memory = '1 GB'
    time = '2m 30s'
    
    input:
    path expe_folder

    output:
    path expe_folder

    publishDir "${params.outdir}/codegen_results", mode: 'copy'

    script:
    """
    echo "Generating code for TPG model in ${expe_folder}"
    sed -i 's/"testPath": "outLogs"/"testPath": ".\\/outLogs\\/out_best.dot"/' ./${expe_folder}/params/trainParams.json
    apptainer exec --bind ${expe_folder}/params:/params/ --bind ${expe_folder}/outLogs:/outLogs/ ${params.projectRoot}/containers/gegelati-arm.sif /bin/bash -c "cd / && ./armlearn-wrapper/build/armGraphPruner"

    # Retrieve the instrType from params/trainParams.json
    params_json_path="${expe_folder}/params/trainParams.json"
    if [ -f "\${params_json_path}" ]; then
        instrType=\$(grep '"instrType"' "\${params_json_path}" | sed 's/.*: *"\\([^"]*\\)".*/\\1/')
    else
        # Error handling if the file does not exist
        echo "Error: params/trainParams.json not found in ${expe_folder}"
        exit 1
    fi

    echo "Convert registers to \${instrType} format"
    # Patch codeGenArmlearn.c to use the correct type for bestScore and challengerScore
    codegen_c_file="${expe_folder}/outLogs/codeGen/codeGenArmlearn.c"
    if [ -f "\${codegen_c_file}" ]; then
        # Always replace the function signature and pointer type
        sed -i "s/int bestProgram(double \\*results, int nb)/int bestProgram(\${instrType} *results, int nb)/" "\${codegen_c_file}"

        # Replace double TnScores with \${instrType} TnScores
        sed -i -E "s/double T([0-9]+)Scores/\${instrType} T\\1Scores/g" "\${codegen_c_file}"

        if [ "\${instrType}" = "int" ]; then
            # For int, remove isnan/-INFINITY logic and set type
            sed -i 's/double bestScore = (isnan(results\\[0\\]))? -INFINITY : results\\[0\\];/int bestScore = results[0];/' "\${codegen_c_file}"
            sed -i 's/double challengerScore = (isnan(results\\[i\\]))? -INFINITY : results\\[i\\];/int challengerScore = results[i];/' "\${codegen_c_file}"
        else
            # For float/double, just change the type
            sed -i "s/double bestScore =/\${instrType} bestScore =/" "\${codegen_c_file}"
            sed -i "s/double challengerScore =/\${instrType} challengerScore =/" "\${codegen_c_file}"
        fi
    else
        echo "Warning: \${codegen_c_file} not found, skipping type patch."
    fi

    # Patch codeGenArmlearn_program.h to use the correct type for P functions
    codegen_h_file="${expe_folder}/outLogs/codeGen/codeGenArmlearn_program.h"
    if [ -f "\${codegen_h_file}" ]; then
        sed -i -E "s/double P([0-9]+)\\(\\);/\${instrType} P\\1();/g" "\${codegen_h_file}"
    else
        echo "Warning: \${codegen_h_file} not found, skipping header patch."
    fi
    """
}