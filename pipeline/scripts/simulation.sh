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

# hardcoded applications names
app_default="tpg_inference_instrTPG"
app_instr="tpg_inference_instrTeams_instrTPG"
 
# paths
params_dir="${tpg_folder}/params"
outlogs_dir="${tpg_folder}/outLogs"
inference_dir="${tpg_folder}/inference"
simulators_dir="${project_root}/x-heep/experimentations/microarchitectures/simulators"
echo "TPG folder: ${tpg_folder}"

# display all parameters
echo "tpg=${tpg}"
echo "uarch=${uarch} isa=${isa} abi=${abi} dtype=${dtype_lower} compiler=${compiler}"
echo "dtype_upper=${dtype_upper}"
echo "dtype_lower=${dtype_lower}"
echo "params_dir=${params_dir}"
echo "outlogs_dir=${outlogs_dir}"
echo "inference_dir=${inference_dir}"
echo "simulators_dir=${simulators_dir}"
echo "project_root=${project_root}"

# build 128MB Apptainer overlay 
apptainer overlay create --size 512 "${inference_dir}/overlays/overlay_${uarch}_${isa}_${abi}_${dtype_lower}.img" 
realpath "${project_root}/containers/x-heep.sif"

# run Apptainer
# Run non-instrumented TPG inference, then instrumented TPG inference
apptainer exec \
    --overlay "${inference_dir}/overlays/overlay_${uarch}_${isa}_${abi}_${dtype_lower}.img" \
    --bind $params_dir:/params/ \
    --bind $outlogs_dir:/outLogs/ \
    --bind $inference_dir:/inference/ \
    --bind $simulators_dir:/x-heep/experimentations/microarchitectures/simulators/:ro \
    ${project_root}/containers/x-heep.sif \
    /bin/bash -c "\
    export XDG_CACHE_HOME=/inference/cache && mkdir -p /inference/cache && \

    cp /outLogs/codegen/TPG* /x-heep/sw/applications/tpg_modelization/${app_default}/codegen/. && \
    cp /outLogs/precalcul/LE_states.h /x-heep/sw/applications/tpg_modelization/${app_default}/precalcul/. && \

    cp /outLogs/codegen_TeamsInstrumented/TPG* /x-heep/sw/applications/tpg_modelization/${app_instr}/codegen/. && \
    cp /outLogs/precalcul/LE_states.h /x-heep/sw/applications/tpg_modelization/${app_instr}/precalcul/. && \

    cd /x-heep && \

    mkdir -p experimentations/simulations && \
    ls experimentations/simulations/ && \

    ./scripts/generate-mcu/generate-mcu.sh ${uarch} && \

    ./scripts/automatic-simulation/simulation.sh tpg_modelization/${app_default} ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler} False && \
    
    ./scripts/automatic-simulation/simulation.sh tpg_modelization/${app_instr} ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler} True && \

    ./scripts/compile_disassemble/compile_disassemble.sh tpg_modelization/${app_default} ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler} && \

    ./scripts/compile_disassemble/compile_disassemble.sh tpg_modelization/${app_instr} ${uarch} ${isa} ${abi} ${dtype_upper} ${compiler} && \

    mkdir -p /inference/results/${uarch}_${isa}_${abi}_${dtype_lower} && \

    mv experimentations/compilations/disassembly_${app_default}.txt /inference/results/${uarch}_${isa}_${abi}_${dtype_lower}/. && \

    mv experimentations/compilations/disassembly_${app_instr}.txt /inference/results/${uarch}_${isa}_${abi}_${dtype_lower}/. && \

    mv experimentations/simulations/${uarch}_${isa}_${abi}_${dtype_lower}.json /inference/results/${uarch}_${isa}_${abi}_${dtype_lower}/latencies.json"

rm "${inference_dir}/overlays/overlay_${uarch}_${isa}_${abi}_${dtype_lower}.img"