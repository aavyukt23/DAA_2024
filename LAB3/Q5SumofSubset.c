#include <stdio.h>

// Function to print a solution
void printSolution(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Backtracking function to find subsets
void sumOfSubset(int set[], int subset[], int n, int subsetSize, int total, int target, int index) {
    // If the total matches the target, print the subset
    if (total == target) {
        printSolution(subset, subsetSize);
        return;
    }

    // If total exceeds the target or we've considered all items, stop
    if (index == n || total > target) {
        return;
    }

    // Include the current element in the subset
    subset[subsetSize] = set[index];
    sumOfSubset(set, subset, n, subsetSize + 1, total + set[index], target, index + 1);

    // Exclude the current element from the subset
    sumOfSubset(set, subset, n, subsetSize, total, target, index + 1);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 9;

    int subset[n]; // To store the current subset
    printf("Subsets with sum %d:\n", target);
    sumOfSubset(set, subset, n, 0, 0, target, 0);

    return 0;
}
