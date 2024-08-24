# Compiling

# Min g++ optimization
# g++ -O0 matrix.cpp -o matrix.out

# Max g++ optimization
g++ -O3 matrix.cpp -o matrix.out

# Running
time -p ./matrix.out 2000

# Deleting
rm -if matrix.out