#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
    double ratio;  // value-to-weight ratio
};

// Function to compare two items based on their value-to-weight ratio
int compare(const void* a, const void* b) {
    struct Item* item1 = (struct Item*) a;
    struct Item* item2 = (struct Item*) b;
    
    // Sorting in descending order of value/weight ratio
    if (item1->ratio > item2->ratio) return -1;
    if (item1->ratio < item2->ratio) return 1;
    return 0;
}

// Function to calculate the maximum value for the fractional knapsack problem
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items by their value-to-weight ratio in descending order
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0; // Variable to store the total value in the knapsack
    int remainingCapacity = capacity;

    // Iterate over the sorted items
    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0) break;  // No more capacity in the knapsack

        // If the item can fit completely into the knapsack
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // If the item cannot fit completely, take the fraction of it
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            remainingCapacity = 0;  // Knapsack is full now
        }
    }

    return totalValue;
}

// Main function to test the fractional knapsack algorithm
int main() {
    int n, capacity;

    // Input number of items and capacity of the knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];

    // Input weight and value for each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        // Calculate the value-to-weight ratio for each item
        items[i].ratio = (double) items[i].value / items[i].weight;
    }

    // Calculate and output the maximum value that can be obtained
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value that can be obtained: %.2f\n", maxValue);

    return 0;
}
