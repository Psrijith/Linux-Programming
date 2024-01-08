#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

directory_path=$1

# Check if the directory exists
if [ ! -d "$directory_path" ]; then
    echo "Directory '$directory_path' not found."
    exit 1
fi

# Display a list of all files in the specified directory
ls -l "$directory_path"

