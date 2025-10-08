# TPG Nextflow Pipeline

This project automates the generation, training, and code generation of Tangled Program Graphs (TPG) using Nextflow and Apptainer containers.

## Features

- **Containerized:** Uses Apptainer for reproducible environments.

- **Config Generation:** Automatically creates experiment configurations varying instruction sets and data types.
- **Training:** Trains TPG models in parallel using SLURM.
- **Result Parsing:** Aggregates training results for analysis.
- **Code Generation:** Generates and patches C code for trained TPGs.
- **Inference:** Realize inference on the Learning Environment.

## Usage

Build containers and launch the pipeline:

```sh
./launcher.sh
```

Configuration files are in [`configs/`](configs), pipeline scripts in [`pipeline/`](pipeline), and containers in [`containers/`](containers).

##