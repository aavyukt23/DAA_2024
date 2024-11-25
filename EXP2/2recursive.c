#include <stdio.h>

// Recursive Binary Search Function
int binary_search_recursive(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1; // Element not found
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == x) {
        return mid; // Element found at index mid
    }
    if (arr[mid] < x) {
        return binary_search_recursive(arr, mid + 1, high, x); // Search in the right half
    } else {
        return binary_search_recursive(arr, low, mid - 1, x); // Search in the left half
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7; // Element to search for

    int result = binary_search_recursive(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element %d found at index %d.\n", x, result);
    } else {
        printf("Element %d not found.\n", x);
    }
    
    return 0;
}
