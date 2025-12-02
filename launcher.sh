#!/bin/bash

# Default value
mini_config=0

# Parse optional argument --mini_config=VALUE
for arg in "$@"; do
    case $arg in
        --mini_config=*)
            mini_config="${arg#*=}"
            shift
            ;;
        --target=*)
            target="${arg#*=}"
            shift
            ;;
    esac
done

# If no target provided, prompt the user (fail in non-interactive shells)
if [ -z "$target" ]; then
    if [ -t 0 ]; then
        echo "Select target pipeline:"
        echo "  1) train"
        echo "  2) prepare_inference"
        echo "  3) inference"
        read -p "Enter choice (train/prepare_inference/inference): " target
    else
        echo "Error: --target must be provided in non-interactive mode. Allowed: train, prepare_inference, inference"
        exit 1
    fi
fi

# Map target to pipeline file
case "$target" in
    train|train.nf)
        target_file="./pipeline/train.nf"
        selected_config="./configs/trainings.config"
        ;;
    prepare_inference|prepare_inference.nf)
        target_file="./pipeline/prepare_inference.nf"
        selected_config="./configs/prepare_inference.config"
        ;;
    inference|inference.nf)
        target_file="./pipeline/inference.nf"
        selected_config="./configs/inference.config"
        ;;
    *)
        echo "Invalid target: $target. Allowed values: train, prepare_inference, inference"
        exit 1
        ;;
esac

log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*"
}

# Trap SIGINT and terminate Nextflow gracefully
trap 'log "Terminating Nextflow..."; kill $(pgrep -f "nextflow"); exit 0' SIGINT

# launcher.sh - Script to launch the TPG pipeline

# Set the working directory to the script's location
cd "$(dirname "$0")"

log "Build containers"

# Find all container definition files
container_defs=()
for def_file in containers/*.def; do
    [ -e "$def_file" ] || continue
    container_defs+=("$(basename "$def_file" .def)")
done
log "Found containers: ${container_defs[*]}"

# Build containers if they don't exist or are outdated
for container in "${container_defs[@]}"; do
    sif_file="containers/${container}.sif"
    def_file="containers/${container}.def"
    if [ ! -f "$sif_file" ] || [ "$def_file" -nt "$sif_file" ]; then
        log "Building container: $container"
        apptainer build --force "$sif_file" "$def_file"
    else
        log "Container is up-to-date: $container"
    fi
done

log "Using mini_config=$mini_config, target=$target_file, config=$selected_config"
log "Start pipeline with nextflow"

apptainer exec \
    --bind /etc/munge:/etc/munge \
    --bind /run/munge:/run/munge \
    --bind /etc/slurm:/etc/slurm \
    containers/nextflow-insa.sif \
    nextflow run "$target_file" \
    --mini_config="$mini_config" \
    --projectRoot "$(pwd)" \
    -c ./configs/nextflow.config \
    -c "$selected_config" \
    -with-report -with-dag \
    "$@"
