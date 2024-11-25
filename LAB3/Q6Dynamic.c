#include <stdio.h>

// Function to implement the 0/1 Knapsack Problem using Dynamic Programming
int knapsackDP(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: If no items or capacity is 0
            } else if (weights[i - 1] <= w) {
                // If the current item can fit in the knapsack
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) 
                           ? (values[i - 1] + dp[i - 1][w - weights[i - 1]]) 
                           : dp[i - 1][w];
            } else {
                // If the current item cannot fit in the knapsack
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity]; // The bottom-right corner of the DP table holds the maximum value
}

int main() {
    // Example input
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    // Call the knapsackDP function
    int maxProfit = knapsackDP(weights, values, n, capacity);

    // Output the result
    printf("Maximum profit using Dynamic Programming Approach: %d\n", maxProfit);
    return 0;
}
