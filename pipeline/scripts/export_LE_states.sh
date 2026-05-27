#/bin/bash

# this script does codegen of the TPG for both the instrumented, decorated at Team level TPG and the default 
# non-instrumented + non-decorated at Team level TPG 

# set -euo pipefail is used to make the script exit on error, undefined variable, or error in a pipeline
set -euo pipefail

tpg_folder="$1"
project_root="$2"

# build 128MB Apptainer overlay 
overlay_img="${tpg_folder}/overlay/overlay.img"
if [ ! -f "$overlay_img" ]; then
    mkdir "${tpg_folder}/overlay"
    apptainer overlay create --size 128 "$overlay_img"
else
    echo "Overlay already exists: $overlay_img"
fi

# Get instrType
INSTR_TYPE=$(jq -r '.instrType' "${tpg_folder}/params/trainParams.json")

# Map instrType → compiler flags
case "$INSTR_TYPE" in
    double)
        export CXXFLAGS="-DUSE_DOUBLE"
        export CFLAGS="-DUSE_DOUBLE"
        ;;
    float)
        export CXXFLAGS="-DUSE_FLOAT"
        export CFLAGS="-DUSE_FLOAT"
        ;;
    int)
        export CXXFLAGS="-DUSE_INT"
        export CFLAGS="-DUSE_INT"
        ;;
    fixedpt)
        export CXXFLAGS="-DUSE_FIXEDPT"
        export CFLAGS="-DUSE_FIXEDPT"
        ;;
    *)
        echo "Unknown instrType: $INSTR_TYPE"
        exit 1
        ;;
esac

# run the exportLEstates program in the Singularity container
apptainer exec \
    --overlay "${tpg_folder}/overlay/overlay.img" \
    --bind ${tpg_folder}/params:/params/ \
    --bind ${tpg_folder}/outLogs:/outLogs/ \
    ${project_root}/containers/gegelati-armlearn.sif \
    /bin/bash -c \
        "cd / \
        && cp armlearn-wrapper/params/AllTarget.csv /params/. \
        && cp armlearn-wrapper/params/ValidationTrajectories.txt /params/. \
        && cd /armlearn-wrapper \
        && rm -rf build \
        && mkdir build && cd build \
        && CXXFLAGS=\"$CXXFLAGS\" CFLAGS=\"$CFLAGS\" cmake .. \
        && make exportLEstates \
        && cd ../.. \
        && ./armlearn-wrapper/build/exportLEstates \
        && rm /params/AllTarget.csv /params/ValidationTrajectories.txt"

rm "${tpg_folder}/overlay/overlay.img" 
rmdir "${tpg_folder}/overlay"