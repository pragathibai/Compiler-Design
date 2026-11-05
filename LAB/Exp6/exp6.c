
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char str[]) {
    char *keywords[] = {
        "int", "float", "char", "double", "if",
        "else", "while", "for", "return", "void",
        "break", "continue", "switch", "case",
        "long", "short", "const", "static"
    };

    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int main() {
    char id[100];
    int i, valid = 1;

    printf("Enter an identifier: ");
    scanf("%99s", id);

    if (!(isalpha((unsigned char)id[0]) || id[0] == '_'))
        valid = 0;

    for (i = 1; id[i] != '\0'; i++) {
        if (!(isalnum((unsigned char)id[i]) || id[i] == '_')) {
            valid = 0;
            break;
        }
    }

    if (isKeyword(id))
        valid = 0;

    if (valid)
        printf("%s is a valid identifier.\n", id);
    else
        printf("%s is an invalid identifier.\n", id);

    return 0;
}
