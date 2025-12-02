#!/usr/bin/env python3
import json
import os
import re
import shutil
import sys

def copy_files(expe_folder, custom_params_path, use_local_params):
    # Copies required parameter and log files from the container (armlearn-wrapper) to the experiment folder.
    # These files are then modified to create a unique experiment configuration.
    container_src_folder = '/armlearn-wrapper/params/' # Within gegelati-armlearn apptainer container
    params_folder = os.path.join(expe_folder, 'params')
    os.makedirs(params_folder, exist_ok=True)
    out_logs_folder = os.path.join(expe_folder, 'outLogs', 'dotfiles')
    os.makedirs(out_logs_folder, exist_ok=True)
    # AllTarget.csv and ValidationTrajectories.txt are cp and rm at runtime,
    # we don't copy them to save space.
    files_to_copy = ['trainParams.json']
    for file_name in files_to_copy:
        src_file_path = os.path.join(container_src_folder, file_name)
        dest_file_path = os.path.join(params_folder, file_name)
        shutil.copy2(src_file_path, dest_file_path)
    # Handle params.json (custom or default)
    params_dest_path = os.path.join(params_folder, 'params.json')
    if use_local_params and os.path.exists(custom_params_path):
        shutil.copy2(custom_params_path, params_dest_path)
    else:
        src_params_path = os.path.join(container_src_folder, 'params.json')
        shutil.copy2(src_params_path, params_dest_path)
    # display copied files
    #print("Copied files to experiment folder:")
    #for file in os.listdir(params_folder):
    #    print(" -", file)


def experiment_name(config):
    # Generates a unique experiment folder name based on parameter key-value pairs.
    return '_'.join(f"{key}-{value}" for key, value in config.items() if key != 'instrSetName')

def modify_json(expe_folder, config, training_time, training_cores):
    # Updates JSON config files with experiment config.
    # The training_time and training_cores values are provided by Nextflow config (see trainings.config).
    pattern = r'//.*?\n|/\*.*?\*/'
    train_params_path = os.path.join(expe_folder, 'params', 'trainParams.json')
    with open(train_params_path, 'r') as json_file:
        json_content = json_file.read()
    json_uncommented = re.sub(pattern, '', json_content, flags=re.DOTALL | re.MULTILINE)
    data = json.loads(json_uncommented)
    data['timeMaxTraining'] = int(training_time)  # From Nextflow config
    for key, value in config.items():
        if key in data:
            data[key] = value
        elif key != 'instrSetName':
            print(f"Key '{key}' not found in JSON file.")
        else:
            data[key] = value
    with open(train_params_path, 'w') as json_file:
        json.dump(data, json_file, indent=4)
    # Modify params.json to set nbThreads
    if os.path.exists(os.path.join(expe_folder, 'params', 'params.json')):
        params_json_path = os.path.join(expe_folder, 'params', 'params.json')
    else:
        print("No params.json file found to modify.")
        return
    with open(params_json_path, 'r') as json_file:
        params_content = json_file.read()
        params_uncommented = re.sub(pattern, '', params_content, flags=re.DOTALL | re.MULTILINE)
        params_data = json.loads(params_uncommented)
        params_data['nbThreads'] = int(training_cores)  # From Nextflow config
        with open(params_json_path, 'w') as json_file:
            json.dump(params_data, json_file, indent=4)

def main():
    # Main entry point: parses arguments, creates experiment folder, copies files from container,
    # and modifies the configuration using config and Nextflow config values.
    config = json.loads(sys.argv[1])
    training_time = sys.argv[2]
    nb_generations = sys.argv[3]
    training_cores = sys.argv[4]
    custom_params_path = sys.argv[5]
    use_local_params = sys.argv[6].lower() == 'true'
    print("use_local_params:", use_local_params) 
    print(f"Use local params.json: {use_local_params}")
    print(f"Custom params.json path: {custom_params_path}")
    expe_name = experiment_name(config)
    expe_folder = expe_name
    print(f"Generate_configs.py: Generating configuration for experiment: {expe_name}")
    copy_files(expe_folder, custom_params_path, use_local_params)
    modify_json(expe_folder, config, training_time, training_cores)

if __name__ == "__main__":
    main()