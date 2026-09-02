#!/bin/bash

# Delete every inference folder under tpg_expe/
# find tpg_expe/*/* -type d -name "inference" -exec rm -r {} +

# delete work folder 
rm -rf work

# delete log, dag and report files
rm -rf .nextflow*
rm -rf dag-*.html
rm -rf report-*.html