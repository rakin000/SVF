#!/bin/bash

for file in *.ll; do
    if [ -f "$file" ]; then
	filename_without_extension="${file%.*}"
        new_filename="${filename_without_extension}.mssa"
        
        wpa -fspta -dump-mssa "$file" > "$new_filename"
        
        if [ $? -eq 0 ]; then
            echo "Successfully processed $file into $new_filename"
        else
            echo "Failed to process $file"
        fi
    fi
done

