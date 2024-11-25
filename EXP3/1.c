#include <stdio.h>

// Recursive Function to Calculate Sum of First n Natural Numbers
int sum_of_natural_numbers(int n) {
    if (n == 1) {
        return 1;  // Base case: sum of first 1 natural number
    }
    return n + sum_of_natural_numbers(n - 1); // Recursive case
}

int main() {
    int n = 5;  // Example: sum of first 5 natural numbers

    int result = sum_of_natural_numbers(n);
    printf("Sum of first %d natural numbers is: %d\n", n, result);
    
    return 0;
}
