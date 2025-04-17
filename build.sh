#!/bin/bash

# Check for gcc
if ! command -v gcc &> /dev/null; then
    echo "gcc is not installed"
    echo "Installing gcc..."
    sudo apt install gcc
fi

echo "Building binaries..."

# Array of challenge directories
challenges=("1a" "1b" "2a" "2b")

# Process each challenge directory
for challenge in "${challenges[@]}"; do
    echo "Processing challenge $challenge..."
    
    # Create build directory if it doesn't exist
    mkdir -p "$challenge/build"
    
    # Compile the C file
    if [ -f "$challenge/src/chal.c" ]; then
        echo "Compiling $challenge/src/chal.c..."
        gcc -no-pie -fno-stack-protector "$challenge/src/chal.c" -o "$challenge/build/chal"
        if [ $? -eq 0 ]; then
            echo "Successfully built $challenge/build/chal"
        else
            echo "Failed to build $challenge/build/chal"
        fi
    else
        echo "Warning: $challenge/src/chal.c not found"
    fi
done

echo "Build process completed."


