#!/bin/bash 

# builds the executable for the generated TPG code
# Usage: ./build_executables.sh <expe_folder>

# set -euo pipefail is used to make the script exit on error, undefined variable, or error in a pipeline
set -euo pipefail

expe_folder=$1

echo "Building code for TPG model in ${expe_folder}"

# Copy the armlearn-wrapper folder to be able to modify its content (/armlean-wrapper is read-only in the Singularity container)
cp -r /armlearn-wrapper ./ 

# Copy generated code files into src/codegen
cp ${expe_folder}/outLogs/codegen/TPG_program.* armlearn-wrapper/src/codegen
cp ${expe_folder}/outLogs/codegen/TPG.* armlearn-wrapper/src/codegen

# Get instrType to know how to compile
INSTR_TYPE=$(jq -r '.instrType' ${expe_folder}/params/trainParams.json)

cd ./armlearn-wrapper/build
rm -rf *

# Configure compilation according to instruction type
case "$INSTR_TYPE" in
    double)
        CXXFLAGS="-DUSE_DOUBLE" CFLAGS="-DUSE_DOUBLE" cmake ..
        ;;
    float)
        CXXFLAGS="-DUSE_FLOAT" CFLAGS="-DUSE_FLOAT" cmake ..
        ;;
    int)
        CXXFLAGS="-DUSE_INT" CFLAGS="-DUSE_INT" cmake ..
        ;;
    fixedpt)
        CXXFLAGS="-DUSE_FIXEDPT" CFLAGS="-DUSE_FIXEDPT" cmake ..
        ;;
    *)
        echo "Unknown instrType: $INSTR_TYPE"
        exit 1
        ;;
esac


cmake --build . --target InferenceBenchmark

cd ../..
# Move the executable to the output folder
mv ./armlearn-wrapper/build/InferenceBenchmark ${expe_folder}/outLogs/codegen/.