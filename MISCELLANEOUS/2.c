#include <stdio.h>
#include <limits.h>

// Function to perform Matrix Chain Multiplication using Dynamic Programming
int MatrixChainMultiplication(int p[], int n) {
    int dp[n][n];

    // Initialize the diagonal elements (base case: no cost for a single matrix)
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // L is the chain length.
    for (int L = 2; L < n; L++) {
        for (int i = 0; i < n - L; i++) {
            int j = i + L;
            dp[i][j] = INT_MAX;

            // Try all possible places to split the matrix chain
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k+1][j] + p[i] * p[k+1] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    // Define matrix dimensions for N = 10, 50, 100
    int p1[] = {10, 20, 30, 40, 30}; // Example matrices dimensions for N = 5
    int p2[] = {10, 20, 30, 40, 50, 60}; // Example matrices dimensions for N = 6
    int p3[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Example for N = 10

    // For simplicity, we will calculate the theoretical and actual values for N = 5, 6, and 10
    int n1 = sizeof(p1) / sizeof(p1[0]);
    int n2 = sizeof(p2) / sizeof(p2[0]);
    int n3 = sizeof(p3) / sizeof(p3[0]);

    // Calculate minimum number of scalar multiplications for different chain lengths
    int result1 = MatrixChainMultiplication(p1, n1);
    int result2 = MatrixChainMultiplication(p2, n2);
    int result3 = MatrixChainMultiplication(p3, n3);

    // Output the results
    printf("Minimum number of scalar multiplications for N=5: %d\n", result1);
    printf("Minimum number of scalar multiplications for N=6: %d\n", result2);
    printf("Minimum number of scalar multiplications for N=10: %d\n", result3);

    return 0;
}
