#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <word_to_delete> <file1> [file2 ... fileN]"
    exit 1
fi

word_to_delete=$1
shift  # Remove the first argument (word_to_delete) from the list of arguments

# Iterate through the files and delete lines containing the specified word
for file in "$@"; do
    # Check if the file exists
    if [ ! -e "$file" ]; then
        echo "File '$file' not found."
        continue
    fi

    # Delete lines containing the specified word
    sed -i "/$word_to_delete/d" "$file"

    echo "Deleted lines containing '$word_to_delete' from '$file'."
done

