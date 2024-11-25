#include <stdio.h>

void printDistinctElements(int arr[], int n) {
    printf("Distinct elements in the array:\n");

    for (int i = 0; i < n; i++) {
        int isDistinct = 1; // Assume the element is distinct

        // Check if the element has appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = 0; // Mark as not distinct
                break;
            }
        }

        // If the element is distinct, print it
        if (isDistinct) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print distinct elements
    printDistinctElements(arr, n);

    return 0;
}
