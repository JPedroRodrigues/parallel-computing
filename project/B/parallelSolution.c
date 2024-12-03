#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>

int N;   // Matrix order
int K;  // Submatrix order

// Function to calculate the prefix sum
void prefixSum(int** matrix, int** prefix) {
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         prefix[i][j] = matrix[i][j];

    //         if (i > 0) prefix[i][j] += prefix[i - 1][j];
    //         if (j > 0) prefix[i][j] += prefix[i][j - 1];
    //         if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
    //     }
    // }
    
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            prefix[i][j] = matrix[i][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
        }
    }

    #pragma omp parallel for
    for (int j = 0; j < N; j++) {
        for (int i = 1; i < N; i++) {
            prefix[i][j] += prefix[i - 1][j];
        }
    }
}

// Function to calculate the submatrix sum using prefix sum
int searchSubmatrixSum(int** prefix, int firstRow, int firstCol, int lastRow, int lastCol) {
    int sum = prefix[lastRow][lastCol];
    
    if (firstRow > 0) sum -= prefix[firstRow - 1][lastCol];
    if (firstCol > 0) sum -= prefix[lastRow][firstCol - 1];
    if (firstRow > 0 && firstCol > 0) sum += prefix[firstRow - 1][firstCol - 1];

    return sum;
}

// Function to find the highest value
int max(int a, int b) { return (a > b ? a : b); }

// Function to find the maximum submatrix sum
int maxSubmatrixSum(int** matrix) {

    // Dynamically allocate memory for the prefix sum
    int** prefix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) prefix[i] = (int*)calloc(N, sizeof(int));

    // Calculate prefix sum
    prefixSum(matrix, prefix);

    // Start global max as the minimum integer value possible
    int globalMax = INT_MIN;

    // Parallel region
    #pragma omp parallel
    {
        // Directive used to collapse nested loops into a single loop for parallelization, improving performance
        #pragma omp for collapse(2) reduction(max:globalMax)
        for (int i = 0; i <= N - K; ++i) {
            for (int j = 0; j <= N - K; ++j) {
                // Calculate the actual submatrix sum
                int sum = searchSubmatrixSum(prefix, i, j, i + K - 1, j + K - 1);
                globalMax = max(globalMax, sum);
            }
        }
    }

    // Free memory
    for (int i = 0; i < N; ++i) free(prefix[i]);
    free(prefix);

    return globalMax;
}

int main() {
    scanf("%d %d", &N, &K);
    
    // Dynamically allocate memory for the matrix
    int** matrix = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i) matrix[i] = (int*) malloc(N * sizeof(int));

    // Assign values to the matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            scanf("%d", &(matrix[i][j]));
    }

    // Function to calculate maximum submatrix sum
    int maxSum = maxSubmatrixSum(matrix);
    printf("Max Submatrix %dx%d Sum = %d\n", K, K, maxSum);

    // Free memory
    for (int i = 0; i < N; ++i) free(matrix[i]);
    free(matrix);

    return 0;
}