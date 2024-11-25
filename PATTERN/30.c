//Butterfly Pattern
#include <stdio.h>

int main() {
    int n = 5;

    // Upper part of butterfly
    for (int i = 1; i <= n; i++) {
        // Left side stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // Middle spaces
        for (int j = 1; j <= (2 * (n - i)); j++) {
            printf(" ");
        }
        // Right side stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower part of butterfly
    for (int i = n; i >= 1; i--) {
        // Left side stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // Middle spaces
        for (int j = 1; j <= (2 * (n - i)); j++) {
            printf(" ");
        }
        // Right side stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
