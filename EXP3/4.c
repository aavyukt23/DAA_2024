#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case: factorial of 0 or 1 is 1
    }
    return n * factorial(n - 1);  // Recursive case: n * factorial of (n-1)
}

int main() {
    int n = 5;  // Example: find factorial of 5

    int result = factorial(n);
    printf("Factorial of %d is: %d\n", n, result);

    return 0;
}
