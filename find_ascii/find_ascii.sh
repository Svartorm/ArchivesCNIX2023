#!/bin/sh

# Check if directory path is provided as argument
if [ $# -eq 0 ]; then
    exit 1
fi

# Loop through all files in directory and check if they are ASCII format
for file in "$1"/*; do
    if file "$file" | grep -q "ASCII text"; then
        file_type=$(file "$file")
        echo "${file_type}"
    fi
done