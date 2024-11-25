#include <stdio.h>

int main() {
    int N;
    
    // Input: Read an integer from the user
    printf("Enter a number: ");
    scanf("%d", &N);
    
    // Determine if the number is Even or Odd
    if (N % 2 == 0) {
        printf("%d is Even\n", N);
    } else {
        printf("%d is Odd\n", N);
    }

    return 0;
}
