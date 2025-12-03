#/bin/bash

expe_json="$1"
tpg_folder="$2"
project_root="$3"

echo "Running inference with ${expe_json}"

# read JSON to extract parameters
tpg=$(jq -r '.tpg' ${expe_json})
uarch=$(jq -r '.uarch' ${expe_json})
isa=$(jq -r '.isa' ${expe_json})
abi=$(jq -r '.abi' ${expe_json})
dtype=$(jq -r '.dtype' ${expe_json} | tr '[:lower:]' '[:upper:]')
dtype_upper=$(echo "$dtype" | tr '[:lower:]' '[:upper:]')
dtype_lower=$(echo "$dtype" | tr '[:upper:]' '[:lower:]')
compiler=$(jq -r '.compiler' ${expe_json})

# paths
params_dir="${tpg_folder}/params"
outlogs_dir="${tpg_folder}/outLogs"
inference_dir="${tpg_folder}/inference"
simulators_dir="${project_root}/x-heep/experimentations/microarchitectures/simulators"
echo "TPG folder: ${tpg_folder}"

# display all parameters
echo "tpg=${tpg}"
echo "uarch=${uarch} isa=${isa} abi=${abi} dtype=${dtype_lower} compiler=${compiler}"
echo "params_dir=${params_dir}"
echo "outlogs_dir=${outlogs_dir}"
echo "inference_dir=${inference_dir}"
echo "simulators_dir=${simulators_dir}"
echo "project_root=${project_root}"

# build 32MB Apptainer overlay 
apptainer overlay create --size 512 "${inference_dir}/overlays/overlay_${uarch}_${isa}_${abi}_${dtype_lower}.img" 

# run Apptainer
apptainer exec \
    --overlay "${inference_dir}/overlays/overlay_${uarch}_${isa}_${abi}_${dtype_lower}.img" \
    --bind $params_dir:/params/ \
    --bind $outlogs_dir:/outLogs/ \
    --bind $inference_dir:/inference/ \
    --bind $simulators_dir:/x-heep/experimentations/microarchitectures/simulators/:ro \
    ${project_root}/containers/x-heep.sif \
    /bin/bash -c "\
    cp /outLogs/codegen/TPG* /x-heep/sw/applications/tpg_inference/codegen/. && \
    cp /outLogs/precalcul/LE_states.h /x-heep/sw/applications/tpg_inference/precalcul/. && \
    cd /x-heep && \

    mkdir -p experimentations/simulations && \
    ls experimentations/simulations/ && \
    ./scripts/generate-mcu/generate-mcu.sh ${uarch} && \

    ./scripts/automatic-simulation/simulation.sh tpg_inference ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler} && \
    mv experimentations/simulations/${uarch}_${isa}_${abi}_${dtype_lower}.json /inference/results/."

rm "${inference_dir}/overlays/overlay_${uarch}_${isa}_${abi}_${dtype_lower}.img"