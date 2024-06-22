#!/bin/bash
source "../setup.sh" 
clang -S -emit-llvm *.c 

for file in *.ll; do
    if [ -f "$file" ]; then
        filename_without_extension="${file%.*}"
        new_filename_fspta="${filename_without_extension}.mssa_fspta"
        new_filename_ander="${filename_without_extension}.mssa_ander"
        new_filename_steens="${filename_without_extension}.mssa_steens"
        diff_filename="${filename_without_extension}.diff"
        wpa -fspta -dump-mssa "$file" > "$new_filename_fspta"
        wpa -ander -dump-mssa "$file" > "$new_filename_ander"
        wpa -steens -dump-mssa "$file" > "$new_filename_steens"
        # if [ $? -eq 0 ]; then
            echo "Successfully processed $file"
        # else
            # echo "Failed to process $file"
        # fi
    fi
done
