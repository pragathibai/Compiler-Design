
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char str[]) {
    char *kw[] = {
        "int", "float", "char", "double", "if",
        "else", "while", "for", "return", "void"
    };

    for (int i = 0; i < 10; i++) {
        if (strcmp(str, kw[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, next, token[100];
    int i;

    printf("Enter a C program (Ctrl+Z then Enter to finish):\n");

    while ((ch = getchar()) != EOF) {

        if (isspace(ch))
            continue;

        if (ch == '/') {
            next = getchar();

            if (next == '/') {
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }

            if (next == '*') {
                char prev = '\0';
                while ((ch = getchar()) != EOF) {
                    if (prev == '*' && ch == '/')
                        break;
                    prev = ch;
                }
                continue;
            }

            if (next != EOF)
                ungetc(next, stdin);

            printf("Operator: /\n");
            continue;
        }

        if (ch == '"' || ch == '\'') {
            char quote = ch;
            while ((ch = getchar()) != EOF && ch != quote) {
                if (ch == '\\')
                    getchar();
            }
            continue;
        }

        if (isalpha(ch) || ch == '_') {
            i = 0;
            token[i++] = ch;

            while ((ch = getchar()) != EOF &&
                   (isalnum(ch) || ch == '_')) {
                if (i < 99)
                    token[i++] = ch;
            }

            token[i] = '\0';

            if (ch != EOF)
                ungetc(ch, stdin);

            if (isKeyword(token))
                printf("Keyword: %s\n", token);
            else
                printf("Identifier: %s\n", token);

            continue;
        }

        if (isdigit(ch)) {
            i = 0;
            token[i++] = ch;

            while ((ch = getchar()) != EOF &&
                   (isdigit(ch) || ch == '.')) {
                if (i < 99)
                    token[i++] = ch;
            }

            token[i] = '\0';

            if (ch != EOF)
                ungetc(ch, stdin);

            printf("Constant: %s\n", token);
            continue;
        }

        if (strchr("+-*=<>!%&|^~", ch)) {
            char op[3] = {ch, '\0', '\0'};
            next = getchar();

            if (next == '=' ||
                (next == ch && strchr("+-&|", ch)))
                op[1] = next;
            else if (next != EOF)
                ungetc(next, stdin);

            printf("Operator: %s\n", op);
        }
    }

    return 0;
}
