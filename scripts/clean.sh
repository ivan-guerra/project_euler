#!/bin/bash

project_dir=$(dirname "$(pwd)")
build_dir="$project_dir/builds"
bin_dir="$project_dir/bin"

# Remove the CMake build directory.
if [ -d "$build_dir" ]
then
    echo "removing '$build_dir'"
    rm -rf "$build_dir"
fi

# Remove the binary directory.
if [ -d "$bin_dir" ]
then
    echo "removing '$bin_dir'"
    rm -rf "$bin_dir"
fi
