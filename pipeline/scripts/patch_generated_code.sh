#!/bin/bash

# patches the generated code (TPG in C) to use the correct data types
# Usage: ./patch_generated_code.sh <expe_folder>
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <expe_folder>"
    exit 1
fi
expe_folder="$1"
 
# Retrieve the instrType from params/trainParams.json
params_json_path="${expe_folder}/params/trainParams.json"
if [ -f "${params_json_path}" ]; then
    instrType=$(grep '"instrType"' "${params_json_path}" | sed 's/.*: *"\([^"]*\)".*/\1/')
else
    # Error handling if the file does not exist
    echo "Error: params/trainParams.json not found in ${expe_folder}"
    exit 1
fi

echo "Convert registers to ${instrType} format"

# Patch codeGenArmlearn.c to use the correct type for bestScore and challengerScore
codegen_c_graph_file="${expe_folder}/outLogs/CodeGen/codeGenArmlearn.c"
if [ -f "${codegen_c_graph_file}" ]; then
    # Always replace the function signature and pointer type
    sed -i "s/int bestProgram(double \*results, int nb)/int bestProgram(${instrType} *results, int nb)/" "${codegen_c_graph_file}"

    # replace the function inferenceTPG() signature to use correcpt type 
    sed -i "s/void inferenceTPG(double\* actions) {/void inferenceTPG(${instrType}\* actions) {/" "${codegen_c_graph_file}"

    # Replace double TnScores with ${instrType} TnScores
    sed -i -E "s/double T([0-9]+)Scores/${instrType} T\\1Scores/g" "${codegen_c_graph_file}"

    if [ "${instrType}" = "int" ]; then
        # For int, remove isnan/-INFINITY logic and set type
        sed -i 's/double bestScore = (isnan(results\[0\]))? -INFINITY : results\[0\];/int bestScore = results[0];/' "${codegen_c_graph_file}"
        sed -i 's/double challengerScore = (isnan(results\[i\]))? -INFINITY : results\[i\];/int challengerScore = results[i];/' "${codegen_c_graph_file}"
    else
        # For float/double, just change the type
        sed -i "s/double bestScore =/${instrType} bestScore =/" "${codegen_c_graph_file}"
        sed -i "s/double challengerScore =/${instrType} challengerScore =/" "${codegen_c_graph_file}"
    fi
else
    echo "Warning: ${codegen_c_graph_file} not found, skipping graph c patch."
fi

# Patch CodeGenArmlearn.h to use the correct type for inferenceTPG function
codegen_h_graph_file="${expe_folder}/outLogs/CodeGen/codeGenArmlearn.h"
if [ -f "${codegen_h_graph_file}" ]; then
    # replace the function inferenceTPG() signature to use correcpt type 
    sed -i "s/void inferenceTPG(double\* actions);/void inferenceTPG(${instrType}\* actions);/" "${codegen_h_graph_file}"

    # add C++ extern "C" guards if they are missing
    if ! grep -q 'extern "C"' "${codegen_h_graph_file}"; then
        # insert opening guard after the #define line
        sed -i '/^#define /a\
\
#ifdef __cplusplus\
extern "C" {\
#endif' "${codegen_h_graph_file}"

        # find last #endif and insert closing guard just before it
        ln=$(grep -n '^#endif' "${codegen_h_graph_file}" | tail -n1 | cut -d: -f1)
        if [ -n "${ln}" ]; then
            sed -i "${ln}i#ifdef __cplusplus\n}\n#endif\n" "${codegen_h_graph_file}"
        fi
    fi

else
    echo "Warning: ${codegen_h_graph_file} not found, skipping graph header patch."
fi

# Patch codeGenArmlearn_program.c to use the correct type for all 'double'
codegen_c_program_file="${expe_folder}/outLogs/CodeGen/codeGenArmlearn_program.c"
if [ -f "${codegen_c_program_file}" ]; then
    # change numeric type from double to instrType
    sed -i "s/double/${instrType}/g" "${codegen_c_program_file}"
    # remove extern declarations for inputs (e.g. "extern double* in1;")
    sed -i -E '/^extern[[:space:]]+.*\bin[0-9]+\s*;/d' "${codegen_c_program_file}"
else
    echo "Warning: ${codegen_c_program_file} not found, skipping program c patch."
fi



# Patch codeGenArmlearn_program.h to use the correct type for P functions
codegen_h_program_file="${expe_folder}/outLogs/CodeGen/codeGenArmlearn_program.h"
if [ -f "${codegen_h_program_file}" ]; then
    sed -i -E "s/double P([0-9]+)\(\);/${instrType} P\\1();/g" "${codegen_h_program_file}"
else
    echo "Warning: ${codegen_h_program_file} not found, skipping program header patch."
fi