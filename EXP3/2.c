#include <stdio.h>

// Recursive Function to Calculate nth Fibonacci Number
int fibonacci(int n) {
    if (n == 0) {
        return 0;  // Base case: F(0) = 0
    }
    if (n == 1) {
        return 1;  // Base case: F(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

int main() {
    int n = 10;  // Example: print first 10 Fibonacci numbers

    printf("First %d Fibonacci numbers are:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));  // Print the ith Fibonacci number
    }

    return 0;
}
