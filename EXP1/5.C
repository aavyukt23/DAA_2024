#include <stdio.h>

int main() {
    int num1, num2;
    
    // Input: Read two integers from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Calculate the quotient and remainder
    int quotient = num1 / num2;
    int remainder = num1 % num2;
    
    // Output: Print the quotient and remainder
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
    
    return 0;
}
