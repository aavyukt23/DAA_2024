//Full diamond with numbers
#include <stdio.h>

int main() {
    int n = 5;

    // Upper half
    for (int i = 1; i <= n; i++) {
        // Leading spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // Print numbers
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        // Leading spaces
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        // Print numbers
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
