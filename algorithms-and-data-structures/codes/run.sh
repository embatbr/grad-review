#!/bin/bash

filename=$1

if [ ! -d bin ]; then
    mkdir bin
fi

gcc src/$filename.c -o bin/$filename
bin/$filename