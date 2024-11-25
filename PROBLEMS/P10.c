#include <stdio.h>

void rearrangeArray(int arr[], int n) {
    int result[n]; // Temporary array to store the rearranged values
    int left = 0, right = n - 1, index = 0;

    // Use two pointers to pick elements alternately from the end and start
    while (left <= right) {
        if (index % 2 == 0) {
            result[index++] = arr[right--]; // Pick maximum
        } else {
            result[index++] = arr[left++]; // Pick minimum
        }
    }

    // Copy the rearranged elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements into the array
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Rearrange the array
    rearrangeArray(arr, n);

    // Output the rearranged array
    printf("Array rearranged in maximum-minimum form:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
