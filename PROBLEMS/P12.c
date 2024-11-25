#include <stdio.h>

int main() {
    int rows, cols, count = 0;

    // Input the size of the 2D array
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    // Input elements into the 2D array
    printf("Enter the elements of the %dx%d array:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0) {
                count++; // Increment count for nonzero elements
            }
        }
    }

    // Output the total number of nonzero elements
    printf("The total number of nonzero elements in the array is: %d\n", count);

    return 0;
}
