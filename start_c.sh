#!/bin/bash

WORKING_DIR=$(realpath "$1")
SAMPLE_DIR=$2
GEOMETRY=$3

echo "Working Directory: $WORKING_DIR"
echo "Sample Directory: $SAMPLE_DIR"
echo "Geometry: $GEOMETRY"

# Example command
cd "$WORKING_DIR/samples/$SAMPLE_DIR/C" || exit
make
cd "$WORKING_DIR" || exit

# Execute my_program with arguments
PROGRAM_PATH="$WORKING_DIR/samples/$SAMPLE_DIR/C/my_program"
echo "Program Path: $PROGRAM_PATH"

if [ -f "$PROGRAM_PATH" ]; then
    echo "Executing program..."
    "$PROGRAM_PATH" "$WORKING_DIR/samples/$SAMPLE_DIR/Image/Design" "$WORKING_DIR/samples/$SAMPLE_DIR/TransImg/Design"
else
    echo "Error: Program not found at $PROGRAM_PATH"
fi
