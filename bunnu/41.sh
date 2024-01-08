#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <file1> [file2 ... fileN]"
    exit 1
fi

# Iterate through the arguments and count the occurrence of each word
for file in "$@"; do
    if [ ! -e "$file" ]; then
        echo "$file does not exist."
        continue
    fi

    echo "Word count in $file:"

    # Use tr to convert spaces and punctuation to newlines,
    # then use sort and uniq to count occurrences of each word
    tr -s '[:space:]' '\n' < "$file" | tr -d '[:punct:]' | sort | uniq -c

    echo "-----------------------------"
done

