#include <stdio.h>

void multiplyMatrices(int *a, int *b, int *result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(result + i * c2 + j) = 0; // Initialize result matrix element
            for (int k = 0; k < c1; k++) {
                *(result + i * c2 + j) += *(a + i * c1 + k) * *(b + k * c2 + j);
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input dimensions of the matrices
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    int a[r1][c1], b[r2][c2], result[r1][c2];

    // Input first matrix
    printf("Enter elements of first matrix (%d x %d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix (%d x %d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Multiply matrices using pointers
    multiplyMatrices((int *)a, (int *)b, (int *)result, r1, c1, c2);

    // Print the result matrix
    printf("Product of the matrices (%d x %d):\n", r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
