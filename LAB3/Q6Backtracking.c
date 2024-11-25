#include <stdio.h>

// Backtracking function to find the maximum value
void knapsackBacktrack(int weights[], int values[], int n, int capacity, int index, int currentWeight, int currentValue, int *maxValue) {
    // Base case: all items considered or capacity exceeded
    if (index == n || currentWeight > capacity) {
        if (currentWeight <= capacity && currentValue > *maxValue) {
            *maxValue = currentValue;
        }
        return;
    }

    // Include the current item
    knapsackBacktrack(weights, values, n, capacity, index + 1, currentWeight + weights[index], currentValue + values[index], maxValue);

    // Exclude the current item
    knapsackBacktrack(weights, values, n, capacity, index + 1, currentWeight, currentValue, maxValue);
}

int knapsackBacktracking(int weights[], int values[], int n, int capacity) {
    int maxValue = 0;
    knapsackBacktrack(weights, values, n, capacity, 0, 0, 0, &maxValue);
    return maxValue;
}

int main() {
    // Example input
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    // Call the backtracking function to solve the knapsack problem
    int maxValue = knapsackBacktracking(weights, values, n, capacity);
    
    printf("Maximum value using Backtracking Approach: %d\n", maxValue);
    return 0;
}
