process generate_configs {
    executor = 'slurm'
    container = 'gegelati-arm.sif'
    cpus = 1
    memory = '1 GB'
    time = '1m 30s'
    

    input:
    val(instruction_set)

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
        files_to_copy = ['AllTarget.csv', 'params.json', 'trainParams.json']
        for file_name in files_to_copy:
            src_file_path = os.path.join(src_folder, file_name)
            dest_file_path = os.path.join(params_folder, file_name)
            shutil.copy2(src_file_path, dest_file_path)


    def experiment_name(parameters):
        return '_'.join(f"{key}-{value}" for key, value in parameters.items() if key != 'instrSetName')

    def modify_json(expe_folder, parameters):
        # Load the JSON file
        params_file_path = os.path.join(expe_folder, 'trainParams.json')
        with open(params_file_path, 'r') as json_file:
            json_content = json_file.read()

        # Regular expression to remove both single-line and multi-line comments
        pattern = r'//.*?\\n|/\\*.*?\\*/' # '\' doubled for nextflow compatibility
        json_uncommented = re.sub(pattern, '', json_content, flags=re.DOTALL | re.MULTILINE)
        data = json.loads(json_uncommented)

        # Modify the JSON data
        for key, value in parameters.items():
            if key in data:
                data[key] = value
            elif key != 'instrSetName':
                print(f"Key '{key}' not found in JSON file.")

        # Save the modified JSON data back to the file
        with open(params_file_path, 'w') as json_file:
            json.dump(data, json_file, indent=4)
        
    parameters = {
        'instrSetName': '${instruction_set.instrSetName}',
        'useInstrTrig': ${instruction_set.useInstrTrig ? 'True' : 'False'},
        'useInstrLogExp': ${instruction_set.useInstrLogExp ? 'True' : 'False'},
        'useInstrExpensiveArithmetic': ${instruction_set.useInstrExpensiveArithmetic ? 'True' : 'False'},
        'useInstrComparison': ${instruction_set.useInstrComparison ? 'True' : 'False'}
    }

    expe_name = experiment_name(parameters)
    expe_folder = expe_name  # Create folder directly in work directory
    
    print(f"Generating configuration for experiment: {expe_name}")

    copy_files(expe_folder)
    modify_json(expe_folder + '/params', parameters)
    
    """
}