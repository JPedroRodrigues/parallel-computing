SHELL := /bin/bash
# Compiler
COMPILER = gcc

# Flags
SERIAL_FLAGS = -O3 -Wall
PARALLEL_FLAGS = -O3 -Wall -fopenmp

# Files to compile
SERIAL_OBJECT = solution.c
PARALLEL_OBJECT = parallelSolution.c

# Input file
INPUT = input

#Execution Flags
EXEC_FLAGS = time -p

# Executable names
SERIAL_EXE = solution
PARALLEL_EXE = parallelSolution

# Default target
all: serial parallel

# Rule to compile the serial program
serial: $(SERIAL_OBJECT)
	$(COMPILER) $(SERIAL_OBJECT) $(SERIAL_FLAGS) -o $(SERIAL_EXE)

# Rule to compile the serial program
parallel: $(PARALLEL_OBJECT)
	$(COMPILER) $(PARALLEL_OBJECT) $(PARALLEL_FLAGS) -o $(PARALLEL_EXE)

# Rule to run the serial program
run-serial: serial
	$(EXEC_FLAGS) ./$(SERIAL_EXE) < $(INPUT)

# Rule to run the parallel program
run-parallel: parallel
	$(EXEC_FLAGS) ./$(PARALLEL_EXE) < $(INPUT)

# Clean up the executables
clean:
	rm -f $(SERIAL_EXE) $(PARALLEL_EXE)
