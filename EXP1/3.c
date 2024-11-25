#include <stdio.h>

int main() {
    int num1, num2, num3;
    
    // Input: Read three different numbers from the user
    printf("Enter three different numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    // Find the largest number
    if (num1 >= num2 && num1 >= num3) {
        printf("The largest number is: %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("The largest number is: %d\n", num2);
    } else {
        printf("The largest number is: %d\n", num3);
    }

    return 0;
}
