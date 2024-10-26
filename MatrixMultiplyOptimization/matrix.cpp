#include <iostream>
#include <cstdlib>

using namespace std;

void printMatrix(long **m, int lin, int col) {
    for (int i = 0; i < lin; i++) {
        cout << "|";
        for (int j = 0; j < col; j++) {
            cout << " " << m[i][j] << " |"; 
        }
    }
}


int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    int **a = new int*[n];
    int **b = new int*[n];
    long **c = new long*[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
        c[i] = new long[n];
    }

    int value = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[i][j] = value++;
            c[i][j] = 0;
        }
    }

    // Without cache optimization
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for (int k = 0; k < n; k++) {
    //             c[i][j] += (a[i][k] * b[k][j]);
    //         }
    //     }
    // }

    // With cache optimization
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    return 0;
}