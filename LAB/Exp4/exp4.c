
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200];
    int i;

    printf("Enter an arithmetic expression: ");
    fgets(str, sizeof(str), stdin);

    printf("\nRecognized Arithmetic Operators:\n");

    for (i = 0; str[i] != '\0'; i++) {

        if (str[i] == '+' || str[i] == '-' ||
            str[i] == '*' || str[i] == '/') {

            printf("%c - Valid Arithmetic Operator\n", str[i]);
        }
    }

    return 0;
}
