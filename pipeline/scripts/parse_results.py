 #!/usr/bin/env python3
import os
import pandas as pd
import json
import sys

# This script aggregates training results from multiple experiment folders into a single CSV file. 

# Get the list of input paths from Nextflow
# training_results = "${training_results}".split()
    
def main(training_results):
    results_df = pd.DataFrame()
    for training_result in training_results:
        # Each training_result is a path to a folder
        file = os.path.join(training_result, 'outLogs', 'garbage.ods')
        params_path = os.path.join(training_result, 'params', 'trainParams.json')
        seed = None
        instrType = None
        instrSetName = None
        if os.path.isfile(params_path):
            with open(params_path) as pf:
                params = json.load(pf)
                seed = params.get('seed')
                instrType = params.get('instrType')
                instrSetName = params.get('instrSetName')

        if os.path.isfile(file):
            with open(file) as f:
                lines = f.readlines()
            columns = lines[1].split()
            df = pd.read_csv(file, sep='\\s+', skiprows=2, names=columns)
            df['seed'] = seed
            df['instrType'] = instrType
            df['instrSetName'] = instrSetName
            results_df = pd.concat([results_df, df]) 

    results_df.to_csv('results.csv', index=False)

if __name__ == "__main__":
    training_results = sys.argv[1:]
    main(training_results)