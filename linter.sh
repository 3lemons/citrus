#!/bin/bash
BUILD_DIR=./build
INCLUDE_DIR=./include
BUILD_SRC=src/*.c

TEST=./test
TEST_INCLUDE_DIR=${TEST}/include
TEST_SRC=${TEST}/src/*.c

# Check splint is installed
if ! command -v splint &> /dev/null
then
    echo "splint could not be found. Please install before running linter.sh"
    exit
fi

# Create build dir if it doesn't exist
if [ ! -d ${BUILD_DIR} ]
then
	echo "creating ${BUILD_DIR}"
	mkdir ${BUILD_DIR}
fi

# Run cmake in build dir
(cd ${BUILD_DIR} && cmake ..)

echo "Linting engine"
splint -I${INCLUDE_DIR} -I${BUILD_DIR} ${BUILD_SRC}

echo "Linting tests"
splint ${TEST_SRC} -I${INCLUDE_DIR} -noeffect -nullassign -nullpass
