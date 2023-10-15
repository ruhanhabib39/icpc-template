#!/bin/bash

# prog_A and prog_B are the executables to compare

prog_A=$1
prog_B=$2
generator=$3

inp_file="inp_${generator}.txt"
out_file1="outA_${generator}.txt"
out_file2="outB_${generator}.txt"

for ((i = 1; ; ++i)) do
   echo $i
   "./$generator" > $inp_file
   "./$prog_A" < $inp_file > $out_file1
   "./$prog_B" < $inp_file > $out_file2
   diff -w "${out_file1}" "${out_file2}" || break
done

notify-send "bug found!!!!"

