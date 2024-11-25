#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

    int largest = -1e9, secondLargest = -1e9;
    int smallest = 1e9, secondSmallest = 1e9;

    // Find largest, second largest, smallest, and second smallest
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }

        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    // Swap second largest and second smallest
    for (int i = 0; i < n; i++) {
        if (arr[i] == secondLargest) {
            for (int j = 0; j < n; j++) {
                if (arr[j] == secondSmallest) {
                    swap(&arr[i], &arr[j]);
                    break;
                }
            }
            break;
        }
    }

    // Output the modified array
    printf("Array after swapping second largest and second smallest:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
