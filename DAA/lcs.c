#include <stdio.h>
#include <string.h>

void lcs(char X[], char Y[], int m, int n) {
    int LCS_table[m + 1][n + 1];
    char b[m + 1][n + 1]; // To store arrows (directions)

    // Initialize the table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                LCS_table[i][j] = 0;
                b[i][j] = ' ';
            }
        }
    }

    // Build the LCS table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
                b[i][j] = '↖'; // Diagonal arrow
            } else {
                if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
                    LCS_table[i][j] = LCS_table[i - 1][j];
                    b[i][j] = '↑'; // Up arrow
                } else {
                    LCS_table[i][j] = LCS_table[i][j - 1];
                    b[i][j] = '←'; // Left arrow
                }
            }
        }
    }

    // Print the length of LCS
    printf("Length of LCS: %d\n", LCS_table[m][n]);

    // Construct and print the LCS
    int i = m, j = n;
    char lcsResult[m + n]; // To store the LCS
    int index = LCS_table[m][n]; // Index for lcsResult

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsResult[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (LCS_table[i - 1][j] > LCS_table[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS
    printf("LCS: ");
    for (int k = 0; k < LCS_table[m][n]; k++) {
        printf("%c", lcsResult[k]);
    }
    printf("\n");
}

int main() {
    char X[100], Y[100];
    printf("Enter the first sequence: ");
    scanf("%s", X);
    printf("Enter the second sequence: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}
