process generate_configs {
    executor = 'slurm'
    container = 'gegelati-armlearn.sif'
    cpus = 1
    memory = '1 GB'
    time = '5m'
    
    input:
    val parameters

    output:
    path "*"

    script:
    """
    #!/usr/bin/env python3
    import json
    import os
    import re
    import shutil

    def copy_files(expe_folder):
        src_folder = '/armlearn-wrapper/params/' # Within apptainer 
        params_folder = expe_folder + '/params'
        os.makedirs(params_folder, exist_ok=True)
        out_logs_folder = expe_folder + '/outLogs/dotfiles'
        os.makedirs(out_logs_folder, exist_ok=True)
        files_to_copy = ['AllTarget.csv', 'params.json', 'trainParams.json', 'ValidationTrajectories.txt']
        for file_name in files_to_copy:
            src_file_path = os.path.join(src_folder, file_name)
            dest_file_path = os.path.join(params_folder, file_name)
            shutil.copy2(src_file_path, dest_file_path)


    def experiment_name(parameters):
        return '_'.join(f"{key}-{value}" for key, value in parameters.items() if key != 'instrSetName')

    def modify_json(expe_folder, parameters):
        # Pattern for comment removal in json
        pattern = r'//.*?\\n|/\\*.*?\\*/' # '\' doubled for nextflow compatibility

        # Update trainParams.json as before
        train_params_path = os.path.join(expe_folder, 'trainParams.json')
        with open(train_params_path, 'r') as json_file:
            json_content = json_file.read()
        json_uncommented = re.sub(pattern, '', json_content, flags=re.DOTALL | re.MULTILINE)
        data = json.loads(json_uncommented)
        data['timeMaxTraining'] = ${params.training_time}
        for key, value in parameters.items():
            if key in data:
                data[key] = value
            elif key != 'instrSetName':
                # If the key does not already exist in the JSON, print a warning
                print(f"Key '{key}' not found in JSON file.")
            else:
                # If 'instrSetName', add it to the JSON data
                data[key] = value
        with open(train_params_path, 'w') as json_file:
            json.dump(data, json_file, indent=4)

        # Update nbThreads in params.json only
        params_json_path = os.path.join(expe_folder, 'params.json')
        if os.path.exists(params_json_path):
            with open(params_json_path, 'r') as json_file:
                params_content = json_file.read()
            params_uncommented = re.sub(pattern, '', params_content, flags=re.DOTALL | re.MULTILINE)
            params_data = json.loads(params_uncommented)
            params_data['nbThreads'] = ${params.training_cores}
            with open(params_json_path, 'w') as json_file:
                json.dump(params_data, json_file, indent=4)

    parameters = json.loads('''${groovy.json.JsonOutput.toJson(parameters)}''')
        
    expe_name = experiment_name(parameters)
    expe_folder = expe_name  # Create folder directly in work directory
    
    print(f"Generating configuration for experiment: {expe_name}")

    copy_files(expe_folder)
    modify_json(expe_folder + '/params', parameters)
    
    """
}