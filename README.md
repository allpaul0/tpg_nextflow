# TPG Nextflow Pipeline

This project automates the generation, training, and code generation of Tangled Program Graphs (TPG) using Nextflow and Apptainer containers.

## Features

- **Containerized:** Uses Apptainer for reproducible environments.

- **Config Generation:** Automatically creates experiment configurations varying instruction sets and data types.
- **Training:** Trains TPG models in parallel using SLURM.
- **Result Parsing:** Aggregates training results for analysis.
- **Code Generation:** Generates and patches C code for trained TPGs.
- **Inference:** Realize inference on the Learning Environment.

## Repository structure
Configuration files are in [`configs/`](configs), pipeline scripts in [`pipeline/`](pipeline), and containers in [`containers/`](containers).

## Usage

**Launching**

Build containers and launch the pipeline:

```sh
./launcher.sh
```
On SLURM clusters:
```sh
sbatch --wrap="./launcher.sh"
```
Resume:
```sh
sbatch --wrap="./launcher.sh -resume"
```

Attention à la durée de vie allouée à sbtach.
Utiliser screen si besoin

### parameters

- `params.training_time = 0` sets `"timeMaxTraining": 0` in `trainParams.json` (no time limit).
- `params.training_cores = 48` sets the minimum required cores (most cluster CPUs have 48 cores at INSA).

If the training time is not the **limiting factor** for the training, the **number of generation** is. 

## Miniconfig Usage

**Launching with miniconfig:**
```sh
./launcher.sh --mini_config=1
```
On SLURM clusters:
```sh
sbatch --wrap="./launcher.sh --mini_config=2"
```

### What happens when lauching with miniconfig

**local_params.json** a local hyperparams file is choosen in the miniconfig to avoid doing an entire training for testing nextflow scripts.

## Training Stop Criteria

You can choose between two modes:

- **Time-based:**  
  Set `params.stop_mode = 'time'` and specify `params.training_time`. Training stops after the given time. (ex: 36000s, 10h)

- **Generation-based:**  
  Set `params.stop_mode = 'generations'` and specify `params.nb_generations`. Training stops after the given number of generations.  
  However, SLURM job time (`params.training_time`) should be set to a safe upper bound to avoid premature terminationn therefore we set the variable to 24h by safety. 

## slurm commands
Check the progress of jobs 
```
squeue
``` 
Kill job 
```
scancel $job_id
```
Kill all my jobs
```
scancel --user $user_id
```

## debug procedure 
enter the workdir to reproduce the bug
```
cd work/${id_workdir}/${hash_workdir}
```

interactively connect to the container
```
apptainer shell --bind ${EXPE_CONFIG}/params:/params/ --bind ${EXPE_CONFIG}/outLogs/:/outLogs /home-reseau/$USER/tpg_nextflow/containers/gegelati-armlearn.sif 
```

launch the problematic command and reproduce the error
```
cd /
./armlearn-wrapper/build/armGegelati 
```