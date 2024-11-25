#include <stdio.h>

// Function to solve the 0/1 Knapsack problem
int knapsack(int N, int W, int profit[], int weight[]) {
    // Create a 2D array to store results of subproblems
    int dp[N + 1][W + 1];
    
    // Build the dp array in a bottom-up manner
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or 0 capacity
            }
            else if (weight[i - 1] <= w) {
                // Item can be included, choose the maximum between including and excluding it
                dp[i][w] = (dp[i - 1][w] > dp[i - 1][w - weight[i - 1]] + profit[i - 1]) 
                            ? dp[i - 1][w] 
                            : dp[i - 1][w - weight[i - 1]] + profit[i - 1];
            } else {
                // Item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[N][W];  // The value of the maximum profit
}

int main() {
    // Test case 1: N = 4, W = 8, profit[] = {2, 3, 1, 4}, weight[] = {3, 4, 6, 5}
    int N1 = 4, W1 = 8;
    int profit1[] = {2, 3, 1, 4};
    int weight1[] = {3, 4, 6, 5};
    
    printf("Maximum profit for test case 1: %d\n", knapsack(N1, W1, profit1, weight1));
    
    // Test case 2: N = 3, W = 50, profit[] = {60, 100, 120}, weight[] = {10, 20, 30}
    int N2 = 3, W2 = 50;
    int profit2[] = {60, 100, 120};
    int weight2[] = {10, 20, 30};
    
    printf("Maximum profit for test case 2: %d\n", knapsack(N2, W2, profit2, weight2));
    
    // Test case 3: N = 4, W = 50, profit[] = {2, 5, 8, 1}, weight[] = {10, 15, 6, 9}
    int N3 = 4, W3 = 50;
    int profit3[] = {2, 5, 8, 1};
    int weight3[] = {10, 15, 6, 9};
    
    printf("Maximum profit for test case 3: %d\n", knapsack(N3, W3, profit3, weight3));

    return 0;
}
