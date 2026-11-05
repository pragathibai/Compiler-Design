
#include <stdio.h>

int main() {
    char ch, next;
    int inBlock = 0;

    printf("Enter a C program (Ctrl+Z then Enter to finish):\n");

    while ((ch = getchar()) != EOF) {

        // Ignore single-line comments
        if (!inBlock && ch == '/') {
            next = getchar();

            if (next == '/') {
                while ((ch = getchar()) != '\n' && ch != EOF);
                putchar('\n');
                continue;
            }

            if (next == '*') {
                inBlock = 1;
                continue;
            }

            putchar(ch);
            if (next != EOF)
                ungetc(next, stdin);
            continue;
        }

        // Ignore multi-line comment content
        if (inBlock) {
            if (ch == '*') {
                next = getchar();

                if (next == '/') {
                    inBlock = 0;
                } else if (next != EOF) {
                    ungetc(next, stdin);
                }
            }
            continue;
        }

        // Ignore redundant spaces and tabs
        if (ch == ' ' || ch == '\t')
            continue;

        // Preserve newlines
        if (ch == '\n') {
            putchar('\n');
            continue;
        }

        putchar(ch);
    }

    return 0;
}
