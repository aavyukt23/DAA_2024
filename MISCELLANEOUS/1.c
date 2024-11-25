#include <stdio.h>

// Function to compute the maximum value of the knapsack using dynamic programming
int knapsack(int W, int wt[], int val[], int N) {
    int dp[N + 1][W + 1];

    // Build the dp table
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            // Base case: No items or zero capacity
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // If the weight of the current item is less than or equal to the capacity
            else if (wt[i - 1] <= w) {
                // Max value: either don't include the item or include it
                dp[i][w] = (dp[i - 1][w] > (val[i - 1] + dp[i - 1][w - wt[i - 1]])) ? dp[i - 1][w] : (val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];  // Item can't be included
            }
        }
    }

    // The maximum value that can be obtained
    return dp[N][W];
}

int main() {
    // Number of items
    int N = 4;

    // Weights of items
    int wt[] = {2, 3, 4, 5};

    // Values of items
    int val[] = {3, 4, 5, 6};

    // Capacity of knapsack
    int W = 5;

    // Calling the knapsack function
    int result = knapsack(W, wt, val, N);

    // Output the result
    printf("Maximum value in Knapsack = %d\n", result);

    return 0;
}
