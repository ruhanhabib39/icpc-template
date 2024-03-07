#!/bin/bash

prog_name=$1

g++ "${prog_name}.cpp" -o $prog_name -std=c++17 -g -DDeBuG -Wall -Wshadow -fsanitize=address,undefined && "./$prog_name"
