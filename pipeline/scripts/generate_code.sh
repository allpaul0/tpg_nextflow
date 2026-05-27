#/bin/bash

# this script does codegen of the TPG for both the instrumented, decorated at Team level TPG and the default 
# non-instrumented + non-decorated at Team level TPG 

# set -euo pipefail is used to make the script exit on error, undefined variable, or error in a pipeline
set -euo pipefail

tpg_folder="$1"
project_root="$2"

# runs sed in-place to update the JSON value for "tpgDotPathTraining" 
# in the trainParams.json file to point to the out_best.dot file
#sed -i 's/"tpgDotPathTraining": "outLogs"/"tpgDotPathTraining": ".\/outLogs\/out_best.dot"/' ./${tpg_folder}/params/trainParams.json

# build 128MB Apptainer overlay 
overlay_img="${tpg_folder}/overlay/overlay.img"
if [ ! -f "$overlay_img" ]; then
    mkdir "${tpg_folder}/overlay"
    apptainer overlay create --size 128 "$overlay_img"
else
    echo "Overlay already exists: $overlay_img"
fi
# run the code generation inside the Singularity container
apptainer exec \
    --overlay "${tpg_folder}/overlay/overlay.img" \
    --bind ${tpg_folder}/params:/params/ \
    --bind ${tpg_folder}/outLogs:/outLogs/ \
    ${project_root}/containers/gegelati-armlearn.sif \
    /bin/bash -c \
        "cd / && \
        cp armlearn-wrapper/params/AllTarget.csv /params/. \
        && cp armlearn-wrapper/params/ValidationTrajectories.txt /params/. \
        && cd /armlearn-wrapper \
        && rm -rf build \
        && mkdir build && cd build \
        && cmake .. \
        && make CodeGen \
        && cd ../.. \
        && cp /params/TeamsInstrumented_TPGInstrumented/codegenParams.json /params/codegenParams.json \
        && ./armlearn-wrapper/build/CodeGen \
        && mv /outLogs/codegen /outLogs/codegen_TeamsInstrumented_TPGInstrumented \
        && cp /params/TPGInstrumented/codegenParams.json /params/codegenParams.json \
        && ./armlearn-wrapper/build/CodeGen \
        && mv /outLogs/codegen /outLogs/codegen_TPGInstrumented \
        && rm /params/codegenParams.json \
        && rm /params/AllTarget.csv /params/ValidationTrajectories.txt"

# we don't need to patch anything since the codegen is now data type specific
# no double -> dtype conversion

rm "${tpg_folder}/overlay/overlay.img" 
rmdir "${tpg_folder}/overlay"