#include <stdio.h>

void moveZeroesToEnd(int arr[], int n) {
    int count = 0; // Count of non-zero elements

    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i]; // Move non-zero elements to the front
        }
    }

    // Fill the remaining positions with zeroes
    while (count < n) {
        arr[count++] = 0;
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

    // Move zeroes to the end
    moveZeroesToEnd(arr, n);

    // Output the modified array
    printf("Array after moving zeroes to the end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
