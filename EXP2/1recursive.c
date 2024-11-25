#include <stdio.h>

// Recursive Linear Search Function
int linear_search_recursive(int arr[], int n, int x, int i) {
    if (i == n) {
        return -1; // Element not found
    }
    if (arr[i] == x) {
        return i; // Element found at index i
    }
    return linear_search_recursive(arr, n, x, i + 1); // Search in the next index
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6; // Element to search for

    int result = linear_search_recursive(arr, n, x, 0); // Start with index 0
    if (result != -1) {
        printf("Element %d found at index %d.\n", x, result);
    } else {
        printf("Element %d not found.\n", x);
    }
    return 0;
}
