
#include <stdio.h>

int main() {
    char ch;
    int whitespace = 0, newline = 0;

    printf("Enter text (Ctrl+Z then Enter to finish):\n");

    while ((ch = getchar()) != EOF) {

        if (ch == ' ' || ch == '\t')
            whitespace++;

        if (ch == '\n')
            newline++;
    }

    printf("\nNumber of whitespaces: %d\n", whitespace);
    printf("Number of newline characters: %d\n", newline);

    return 0;
}
