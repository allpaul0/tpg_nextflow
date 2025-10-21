#!/bin/bash

# Default value
mini_config=0

# Parse optional argument --mini_config=VALUE
for arg in "$@"; do
    case $arg in
        --mini-config=*)
            mini_config="${arg#*=}"
            shift # remove this argument from $@
            ;;
    esac
done

echo "Using mini_config=$mini_config"

log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*"
}

# Trap SIGINT and terminate Nextflow gracefully
trap 'log "Terminating Nextflow..."; kill $(pgrep -f "nextflow"); exit 0' SIGINT

# launcher.sh - Script to launch the TPG pipeline

# Set the working directory to the script's location
cd "$(dirname "$0")"

log "Build containers"

container_defs=()
for def_file in containers/*.def; do
    [ -e "$def_file" ] || continue
    container_defs+=("$(basename "$def_file" .def)")
done
log "Found containers: ${container_defs[*]}"

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

log "Start pipeline with nextflow"
apptainer exec \
    --bind /etc/munge:/etc/munge \
    --bind /run/munge:/run/munge \
    --bind /etc/slurm:/etc/slurm containers/nextflow-insa.sif \
    nextflow run ./pipeline/main.nf \
    --mini_config="$mini_config" \
    --projectRoot "$(pwd)" \
    -c ./configs/nextflow.config,./configs/trainings.config \
    -with-report -with-dag \
    "$@"