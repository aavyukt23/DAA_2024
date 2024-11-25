#include <stdio.h>

// Iterative Binary Search Function
int binary_search_iterative(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            return mid; // Element found at index mid
        }
        if (arr[mid] < x) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    
    return -1; // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7; // Element to search for

    int result = binary_search_iterative(arr, n, x);
    if (result != -1) {
        printf("Element %d found at index %d.\n", x, result);
    } else {
        printf("Element %d not found.\n", x);
    }
    
    return 0;
}
