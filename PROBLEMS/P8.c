#include <stdio.h>

void findThreeLargest(int arr[], int n) {
    if (n < 3) {
        printf("Array must contain at least 3 elements.\n");
        return;
    }

    int first = -2147483648, second = -2147483648, third = -2147483648; // Initialize to smallest possible integer value

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != first && arr[i] != second) {
            third = arr[i];
        }
    }

    if (third == -2147483648) {
        printf("Less than three distinct elements found in the array.\n");
    } else {
        printf("The three largest distinct elements are: %d, %d, %d\n", first, second, third);
    }
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

    // Find the largest three distinct elements
    findThreeLargest(arr, n);

    return 0;
}
