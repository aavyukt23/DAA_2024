#include <stdio.h>

// Struct to represent an item
typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

// Function to sort items by value/weight ratio
void sortItemsByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Greedy approach for 0/1 Knapsack
int greedyKnapsack(Item items[], int n, int capacity) {
    sortItemsByRatio(items, n);

    int totalValue = 0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        }
    }

    return totalValue;
}

int main() {
    // Example input
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].ratio = (double)values[i] / weights[i];
    }

    // Call greedy approach
    int maxValue = greedyKnapsack(items, n, capacity);
    printf("Maximum value using Greedy Approach: %d\n", maxValue);

    return 0;
}
