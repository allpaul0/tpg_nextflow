#!/bin/bash

apptainer exec \
    --bind /etc/munge:/etc/munge \
    --bind /run/munge:/run/munge \
    --bind /etc/slurm:/etc/slurm \
    containers/nextflow-insa.sif \
    nextflow run fake_process.nf \
    --projectRoot "$(pwd)" \
    -c ./fake_config.config \
    "$@"
