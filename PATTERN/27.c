//Diamond Pattern with Alphabets
#include <stdio.h>

int main() {
    int n = 5;

    // Upper half of the diamond
    for (int i = 1; i <= n; i++) {
        // Leading spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // Print alphabets
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%c", 'A' + i - 1);
        }
        printf("\n");
    }

    // Lower half of the diamond
    for (int i = n - 1; i >= 1; i--) {
        // Leading spaces
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        // Print alphabets
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%c", 'A' + i - 1);
        }
        printf("\n");
    }

    return 0;
}
