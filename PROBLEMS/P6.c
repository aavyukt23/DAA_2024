#include <stdio.h>

int main() {
    int n, i, key, found = 0;
    
    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the number to search
    printf("Enter the number to search: ");
    scanf("%d", &key);
    
    // Linear search
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1; // Key found
            break;
        }
    }
    
    // Report success or failure
    if (found) {
        printf("Number %d found at position %d.\n", key, i + 1); // Position is 1-based
    } else {
        printf("Number %d not found in the array.\n", key);
    }
    
    return 0;
}
