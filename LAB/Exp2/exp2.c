
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[500];
    char *p;

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    p = line;

    // Ignore leading spaces and tabs
    while (isspace((unsigned char)*p))
        p++;

    // Check single-line comment
    if (p[0] == '/' && p[1] == '/') {
        printf("It is a single-line comment.\n");
    }

    // Check multi-line comment
    else if (p[0] == '/' && p[1] == '*') {
        if (strstr(p + 2, "*/") != NULL)
            printf("It is a multi-line comment.\n");
        else
            printf("Multi-line comment started, but not closed.\n");
    }

    // Not a comment
    else {
        printf("It is not a comment.\n");
    }

    return 0;
}
