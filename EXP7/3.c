#include <stdio.h>
#include <string.h>

// Function to compute the LCS of two strings
void LCS(char *S1, char *S2) {
    int m = strlen(S1);
    int n = strlen(S2);

    // Create a 2D table to store the lengths of LCS
    int dp[m + 1][n + 1];

    // Fill the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // Base case: LCS of empty string
            } else if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Characters match
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  // Take max
            }
        }
    }

    // The length of the LCS will be in dp[m][n]
    int lcs_length = dp[m][n];
    printf("Length of LCS: %d\n", lcs_length);

    // Reconstruct the LCS string
    char lcs[lcs_length + 1];
    int index = lcs_length;
    lcs[index] = '\0';  // Null-terminate the LCS string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcs[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS string
    printf("LCS: %s\n", lcs);
}

int main() {
    // Input strings
    char S1[] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    char S2[] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

    // Compute and print the LCS
    LCS(S1, S2);

    return 0;
}
