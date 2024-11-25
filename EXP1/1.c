#include <stdio.h>

int main() {
    int sum = 0;
    
    // Loop through numbers from 1 to 999
    for (int i = 1; i < 1000; i++) {
        // Check if the number is divisible by 3 or 5
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;  // Add to sum if divisible
        }
    }

    // Print the result
    printf("Sum of all multiples of 3 or 5 below 1000: %d\n", sum);

    return 0;
}
