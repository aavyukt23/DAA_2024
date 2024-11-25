#include <stdio.h>

// Recursive Binary Search Function
int binary_search_recursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Target not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; // Target found at index mid
    }
    if (arr[mid] < target) {
        return binary_search_recursive(arr, mid + 1, high, target); // Search in the right half
    } else {
        return binary_search_recursive(arr, low, mid - 1, target); // Search in the left half
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7; // Element to search for

    int result = binary_search_recursive(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0;
}
