//Star Pyramid with Spaces in Between
#include <stdio.h>

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // Leading spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // Print stars with spaces in between
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j % 2 == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
