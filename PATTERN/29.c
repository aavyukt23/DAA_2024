//Pyramid of Alphabets (A to Z)
#include <stdio.h>

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = i; j < n; j++) {
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
