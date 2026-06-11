#!/bin/bash

file_name=$1

g++ -std=c++20 -Wall "$file_name" -o practice

if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi

./practice < input.txt
