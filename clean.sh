#!/bin/bash

# Find and remove all /build folders in the current directory and subdirectories
find . -type d -name "build" -exec rm -rf {} + 2>/dev/null

if [ $? -eq 0 ]; then
    echo "Removed all build folders"
else
    echo "build folder not found"
fi