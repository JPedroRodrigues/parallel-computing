gcc parallelSolution.c -o parallelSolution.out -O3 -Wall -fopenmp

time -p ./parallelSolution.out < input OMP_NUM_THREADS=2

rm -if *.out