#!/usr/bin/env python3

import sys
from typing import List, Optional
from aggregate_tpg_results import TPGResultsAggregator


def main(argv: Optional[List[str]] = None):

    if argv is None or len(argv) < 2:
        print("Usage: python find_missing_inference_results.py <root_path>", file=sys.stderr)
        sys.exit(1)

    root = argv[1]

    # Create aggregator
    agg = TPGResultsAggregator(root)

    # print(f"INFO: Searching JSON CONFIG files under {root}/training_results/.../inference/configs/...")
    json_config_files = agg.find_json_files("configs")
    # print(f"INFO: found {len(json_config_files)} JSON CONFIG files")

    # print(f"INFO: Searching JSON RESULT files under {root}/training_results/.../inference/results/...")
    json_result_files = agg.find_json_files("results")
    # print(f"INFO: found {len(json_result_files)} JSON RESULT files")

    # Compute missing results (class handles comparison)
    missing = agg.find_missing_results(json_config_files, json_result_files)
    # print(len(missing))
    
    for m in missing:
        print(m)


if __name__ == "__main__":
    main(sys.argv)
