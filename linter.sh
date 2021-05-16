#!/bin/bash
BUILD_DIR=./build
INCLUDE_DIR=./include
if [ ! -d ${BUILD_DIR} ]
then
	echo "creating ${BUILD_DIR}"
	mkdir ${BUILD_DIR}
fi

(cd build && cmake ..)

splint -I./${INCLUDE} -I${BUILD_DIR} src/*.c
