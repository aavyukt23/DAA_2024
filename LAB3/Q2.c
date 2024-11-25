#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesis placement
void printOptimalParens(int s[][100], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Function to implement the matrix chain multiplication DP solution
void matrixChainOrder(int p[], int n) {
    int dp[100][100]; // DP table to store minimum multiplication costs
    int s[100][100];  // Table to store splitting points

    // Initialize the diagonal to 0 (cost of multiplying one matrix is zero)
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // Chain length (L) ranges from 2 to n
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            // Test all possible splitting points
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k; // Store the splitting point
                }
            }
        }
    }

    // Print the minimum cost
    printf("Minimum number of multiplications: %d\n", dp[1][n - 1]);

    // Print the optimal parenthesis placement
    printf("Optimal parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
}

int main() {
    // Example: dimensions of matrices (p array)
    // Matrices: A1 (10x20), A2 (20x30), A3 (30x40), A4 (40x30)
    int p[] = {10, 20, 30, 40, 30};
    int n = sizeof(p) / sizeof(p[0]);

    // Call the function
    matrixChainOrder(p, n);

    return 0;
}
