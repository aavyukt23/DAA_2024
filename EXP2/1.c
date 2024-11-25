#include <stdio.h>

// Iterative Linear Search Function
int linear_search_iterative(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6; // Element to search for

    int result = linear_search_iterative(arr, n, x);
    if (result != -1) {
        printf("Element %d found at index %d.\n", x, result);
    } else {
        printf("Element %d not found.\n", x);
    }
    return 0;
}
