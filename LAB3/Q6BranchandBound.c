#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for Branch & Bound
typedef struct Node {
    int level, profit, weight;
    double bound;
} Node;

// Comparator for the priority queue
int compare(const void *a, const void *b) {
    return ((Node *)b)->bound > ((Node *)a)->bound ? 1 : -1;
}

// Bound function
double bound(Node u, int n, int capacity, int weights[], int values[]) {
    if (u.weight >= capacity) return 0;

    double bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + weights[j] <= capacity) {
        totalWeight += weights[j];
        bound += values[j];
        j++;
    }

    if (j < n) bound += (capacity - totalWeight) * ((double)values[j] / weights[j]);

    return bound;
}

int knapsackBranchAndBound(int weights[], int values[], int n, int capacity) {
    // Sort items by value/weight ratio (greedy approach for upper bound)
    int *indices = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) indices[i] = i;

    // Sort the items by value-to-weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)values[indices[j]] / weights[indices[j]];
            double ratio2 = (double)values[indices[j + 1]] / weights[indices[j + 1]];
            if (ratio1 < ratio2) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    Node queue[1000];
    int front = 0, rear = 0;

    Node u, v;
    u.level = -1; u.profit = 0; u.weight = 0;
    u.bound = bound(u, n, capacity, weights, values);
    queue[rear++] = u;

    int maxProfit = 0;

    while (front != rear) {
        // Dequeue the next node
        u = queue[front++];

        // Skip if bound is less than the current maximum profit
        if (u.bound > maxProfit) {
            // Explore the next level: include the current item
            v.level = u.level + 1;
            v.weight = u.weight + weights[indices[v.level]];
            v.profit = u.profit + values[indices[v.level]];

            if (v.weight <= capacity && v.profit > maxProfit) {
                maxProfit = v.profit;
            }

            v.bound = bound(v, n, capacity, weights, values);
            if (v.bound > maxProfit) {
                queue[rear++] = v;
            }

            // Explore the next level: exclude the current item
            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = bound(v, n, capacity, weights, values);
            if (v.bound > maxProfit) {
                queue[rear++] = v;
            }
        }
    }

    free(indices);
    return maxProfit;
}

int main() {
    // Example input
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    // Call the Branch and Bound function to solve the knapsack problem
    int maxProfit = knapsackBranchAndBound(weights, values, n, capacity);

    printf("Maximum profit using Branch and Bound Approach: %d\n", maxProfit);
    return 0;
}
