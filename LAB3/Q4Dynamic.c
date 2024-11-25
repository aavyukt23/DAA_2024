#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// DP approach for 0/1 Knapsack
int knapsackDP(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w])
                               ? (values[i - 1] + dp[i - 1][w - weights[i - 1]])
                               : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    // Example input
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    // Call DP approach
    int maxValue = knapsackDP(values, weights, n, capacity);
    printf("Maximum value using DP Approach: %d\n", maxValue);

    return 0;
}
