#include <stdio.h>

int main() {
    char str[100];

    // Input the string
    printf("Enter an uppercase string: ");
    scanf("%s", str);

    // Convert to lowercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Convert uppercase to lowercase
        }
    }

    // Output the result
    printf("Lowercase string: %s\n", str);

    return 0;
}
