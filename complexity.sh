#!/bin/bash

RUNS=1
#RUNS=1
MAXSIZE=100000
#MAXSIZE=100

for ((i = 100, j = 200, k = 500; i <= $MAXSIZE; i *= 10, j *= 10, k *= 10)); do
	echo "size $i"
	for ((a = 0; a < $RUNS; a++)); do
		./randnums $i
		valgrind -q --tool=callgrind ./afonsosort
		./inscnt complexity.csv
		rm callgrind.out.*
	done
	./newline complexity.csv
	for ((a = 0; a < $RUNS; a++)); do
		./randnums $j
		valgrind -q --tool=callgrind ./afonsosort
		./inscnt complexity.csv
		rm callgrind.out.*
	done
	./newline complexity.csv
	for ((a = 0; a < $RUNS; a++)); do
		./randnums $k
		valgrind -q --tool=callgrind ./afonsosort
		./inscnt complexity.csv
		rm callgrind.out.*
	done
	./newline complexity.csv
	./newline complexity.csv
	for ((a = 0; a < $RUNS; a++)); do
		./randnums $i
		valgrind -q --tool=callgrind ./quicksort
		./inscnt complexity.csv
		rm callgrind.out.*
	done
	./newline complexity.csv
	for ((a = 0; a < $RUNS; a++)); do
		./randnums $j
		valgrind -q --tool=callgrind ./quicksort
		./inscnt complexity.csv
		rm callgrind.out.*
	done
	./newline complexity.csv
	for ((a = 0; a < $RUNS; a++)); do
		./randnums $k
		valgrind -q --tool=callgrind ./quicksort
		./inscnt complexity.csv
		rm callgrind.out.*
	done
	./newline complexity.csv
done
