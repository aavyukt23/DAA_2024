#include <stdio.h>
#include <limits.h>

// Function to find the optimal parenthesization of matrix chain multiplication
void matrixChainOrder(int arr[], int n) {
    // Create a table to store the minimum multiplication costs
    int dp[n][n];
    
    // Create a table to store the split points
    int split[n][n];
    
    // Initialize the dp table with 0 for single matrices
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill the dp and split tables
    for (int len = 2; len < n; len++) { // len is the chain length
        for (int i = 0; i < n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX; // Start with a high value
            for (int k = i; k < j; k++) {
                // Calculate the cost of splitting the chain at k
                int q = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    split[i][j] = k;
                }
            }
        }
    }

    // Print the minimum number of multiplications
    printf("Minimum number of multiplications: %d\n", dp[0][n - 2]);

    // Function to print the optimal parenthesization
    printf("Optimal Parenthesization: ");
    printParenthesis(split, 0, n - 2);
    printf("\n");
}

// Function to print the parenthesization from the split table
void printParenthesis(int split[][5], int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        printParenthesis(split, i, split[i][j]);
        printParenthesis(split, split[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    // Test case 1: arr = {40, 20, 30, 10, 30}
    int arr1[] = {40, 20, 30, 10, 30};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Test case 1: arr = {40, 20, 30, 10, 30}\n");
    matrixChainOrder(arr1, n1);

    // Test case 2: arr = {10, 30, 5, 60}
    int arr2[] = {10, 30, 5, 60};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nTest case 2: arr = {10, 30, 5, 60}\n");
    matrixChainOrder(arr2, n2);

    return 0;
}
