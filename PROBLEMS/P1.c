#include <stdio.h>

// Function to calculate sum of array elements using recursion
int sumArray(int arr[], int n) {
    // Base case: if array size is 0, sum is 0
    if (n == 0)
        return 0;
    // Recursive case: sum of last element + sum of rest of the array
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of array

    int sum = sumArray(arr, n); // Call the recursive function
    printf("Sum of array elements: %d\n", sum);

    return 0;
}
