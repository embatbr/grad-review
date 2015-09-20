#!/bin/bash

filename=$1

gcc src/$filename.c -o bin/$filename
./bin/$filename