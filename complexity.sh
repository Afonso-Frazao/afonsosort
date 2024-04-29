#!/bin/bash

RUNS=20
MAXSIZE=1000000

i=100
j=200
k=500

for ((; $i<=$MAXSIZE; $i*=10, $j*=10, $k*=10)); do
	for ((a=0; a<$RUNS; a++)); do
		./randnums $i
		./afonsosort
		./ins complexity.csv
	done
	./newline complexity.csv
	for ((a=0; a<$RUNS; a++)); do
		./randnums $j
		./afonsosort
		./ins complexity.csv
	done
	./newline complexity.csv
	for ((a=0; a<$RUNS; a++)); do
		./randnums $k
		./afonsosort
		./inscomplexity.csv
	done
	./newline complexity.csv
done
./newline complexity.csv
for ((; $i<=$MAXSIZE; $i*=10, $j*=10, $k*=10)); do
        for ((a=0; a<$RUNS; a++)); do
                ./randnums $i
                ./quicksort
                ./ins complexity.csv
        done
        ./newline complexity.csv
        for ((a=0; a<$RUNS; a++)); do
                ./randnums $j
                ./quicksort
                ./ins complexity.csv
        done
        ./newline complexity.csv
        for ((a=0; a<$RUNS; a++)); do
                ./randnums $k
                ./quicksort
                ./inscomplexity.csv
        done
        ./newline complexity.csv
done
