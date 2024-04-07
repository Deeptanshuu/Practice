#include <stdio.h>
#include <string.h>

int naive_string_matcher(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    for (int s = 0; s <= n - m; s++) {
        if (strncmp(text + s, pattern, m) == 0) {
            return s; // valid shift s
        }
    }
    return -1; // no valid shift exists
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline character

    printf("Enter the pattern: ");
    fgets(pattern, 100, stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // remove newline character

    int shift = naive_string_matcher(text, pattern);
    if (shift == -1) {
        printf("No match found.\n");
    } else {
        printf("Pattern found at shift: %d\n", shift);
    }

    return 0;
}