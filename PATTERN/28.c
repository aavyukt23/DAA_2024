//Right-Angled Triangle with Stars and Numbers
#include <stdio.h>

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j % 2 == 1) {
                printf("*");
            } else {
                printf("%d", j);
            }
        }
        printf("\n");
    }
    return 0;
}
