//Number Pyramid
#include <stdio.h>

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // Leading spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // Print numbers
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}
