#include <stdio.h>

int main() {
    // Print even numbers between 100 and 200
    printf("Even numbers between 100 and 200:\n");
    
    // Loop from 100 to 200
    for (int i = 100; i <= 200; i++) {
        // Check if the number is even
        if (i % 2 == 0) {
            printf("%d ", i);  // Print the even number
        }
    }
    
    printf("\n");
    return 0;
}
