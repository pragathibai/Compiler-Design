
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char code[20][100];
    char result[30], op1[30], op2[30], operator;
    int n;

    printf("Enter number of Three Address Code statements: ");
    scanf("%d", &n);
    getchar();

    printf("Enter Three Address Code statements:\n");

    for (int i = 0; i < n; i++) {
        fgets(code[i], sizeof(code[i]), stdin);
        code[i][strcspn(code[i], "\n")] = '\0';
    }

    printf("\nGenerated Target Code:\n");

    for (int i = 0; i < n; i++) {

        if (sscanf(code[i], "%29s = %29s %c %29s",
                   result, op1, &operator, op2) == 4) {

            printf("\n; %s\n", code[i]);
            printf("MOV R0, %s\n", op1);

            switch (operator) {
                case '+':
                    printf("ADD R0, %s\n", op2);
                    break;

                case '-':
                    printf("SUB R0, %s\n", op2);
                    break;

                case '*':
                    printf("MUL R0, %s\n", op2);
                    break;

                case '/':
                    printf("DIV R0, %s\n", op2);
                    break;

                default:
                    printf("Invalid operator\n");
                    continue;
            }

            printf("MOV %s, R0\n", result);
        }

        else if (sscanf(code[i], "%29s = %29s",
                        result, op1) == 2) {

            printf("\n; %s\n", code[i]);
            printf("MOV R0, %s\n", op1);
            printf("MOV %s, R0\n", result);
        }

        else {
            printf("Invalid statement: %s\n", code[i]);
        }
    }

    return 0;
}
