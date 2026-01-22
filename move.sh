#!/bin/bash

# Function to check if a file is an ELF executable
is_executable() {
    file "$1" | grep -q "ELF.*executable"
}

# Find all files in the repository (excluding .git and build directories)
find . -type f -not -path './.git/*' -not -path './build/*' | while read -r file; do
    # Check if the file is an ELF executable
    if is_executable "$file"; then
        # Get the directory of the file
        dir=$(dirname "$file")
        # Create build directory if it doesn't exist
        mkdir -p "$dir/build"
        # Move the executable to the build directory
        mv "$file" "$dir/build/"
        echo "Moved $file to $dir/build/"
    fi
done

echo "Executable files have been moved to their respective build/ directories."