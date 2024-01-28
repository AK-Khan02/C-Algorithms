#include <stdio.h>
#include <math.h>

void gramSchmidt(float A[][2], int m, int n, float Q[][2]) {
    float R[2][2] = {0};

    for (int k = 0; k < n; k++) {
        float norm = 0;
        for (int i = 0; i < m; i++) {
            norm += A[i][k] * A[i][k];
        }
        norm = sqrt(norm);
        R[k][k] = norm;
        for (int i = 0; i < m; i++) {
            Q[i][k] = A[i][k] / R[k][k];
        }
        for (int j = k + 1; j < n; j++) {
            float dot = 0;
            for (int i = 0; i < m; i++) {
                dot += Q[i][k] * A[i][j];
            }
            R[k][j] = dot;
            for (int i = 0; i < m; i++) {
                A[i][j] -= Q[i][k] * R[k][j];
            }
        }
    }
}

int main() {
    float A[2][2] = {{1, 2}, {3, 4}};
    float Q[2][2];
    gramSchmidt(A, 2, 2, Q);

    printf("Q matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", Q[i][j]);
        }
        printf("\n");
    }
    return 0;
}
