#include <stdio.h>
#include <stdlib.h>
int N;
int K;

int max(int a, int b) { return (a > b ? a : b); }

int main() {
	scanf("%d %d", &N, &K);

    // Dynamically allocate memory for the matrix
    int** matrix = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i) matrix[i] = (int*) malloc(N * sizeof(int));

    // Assign values for the matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            scanf("%d", &(matrix[i][j]));
    }

	int sum = 0;

	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			sum += matrix[i][j];

	int maxSum = sum, dir = 1, i = 0, j = 0;

	while (i + K <= N) {
		if ((j + K == N && dir == 1) || (j == 0 && dir == -1)) {
			int exitingRow = i;
			int enteringRow = exitingRow + K;

			if (enteringRow >= N) break;

			for (int k = 0; k < K; k++)
				sum -= matrix[exitingRow][k + j];
			
			for (int k = 0; k < K; k++)
				sum += matrix[enteringRow][k + j];

			i++;
			dir *= -1;

		} else {
			int exitingCol, enteringCol;
			if (dir == 1) {
				exitingCol = j;
				enteringCol = exitingCol + K;
			} else {
				enteringCol = j - 1;
				exitingCol = enteringCol + K;
			}

			for (int k = 0; k < K; k++)
				sum -= matrix[k + i][exitingCol];

			for (int k = 0; k < K; k++)
				sum += matrix[k + i][enteringCol];

			j += dir;
		}

		maxSum = max(maxSum, sum);
	}

	printf("Max Submatrix %dx%d Sum = %d\n", K, K, maxSum);
	
	return 0;
}
