/**
 * How to compile this example: 
 * g++ helloWorld.cpp -o helloWorld -fopenmp
 * 
 * How to run this example:
 * OMP_NUM_THREADS=2 ./helloWorld
 * OMP_NUM_THREADS=4 ./helloWorld
 */

#include <iostream>
#include <omp.h>

int main(int argc, char **argv) {
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        // std::printf("Thread %d: Hello, Parallel World!\n", id);
        std::cout << "Thread: " << id << "Hello, Parallel World!" << std::endl;
    }

    return 0;
}