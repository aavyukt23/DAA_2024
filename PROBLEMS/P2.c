#include <stdio.h>

int main() {
    int n, i, j, value;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a1[n + 1]; // Create an array with extra space for insertion

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &a1[k]);
    }

    // Input the position and value to insert
    printf("Enter the position (i) to insert an element (1-based index): ");
    scanf("%d", &i);
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    // Insert the value at position i (1-based index)
    if (i >= 1 && i <= n + 1) {
        for (int k = n; k >= i - 1; k--) {
            a1[k + 1] = a1[k]; // Shift elements to the right
        }
        a1[i - 1] = value;
        n++; // Increase size after insertion
    } else {
        printf("Invalid insertion position.\n");
        return 1;
    }

    // Input the position to delete
    printf("Enter the position (j) to delete an element (1-based index): ");
    scanf("%d", &j);

    // Delete the element at position j (1-based index)
    if (j >= 1 && j <= n) {
        for (int k = j - 1; k < n - 1; k++) {
            a1[k] = a1[k + 1]; // Shift elements to the left
        }
        n--; // Decrease size after deletion
    } else {
        printf("Invalid deletion position.\n");
        return 1;
    }

    // Print the final array
    printf("Final array:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", a1[k]);
    }
    printf("\n");

    return 0;
}
