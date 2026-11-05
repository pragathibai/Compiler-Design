
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
char operators[100];
char operands[100][30];
int topOp = -1, topVal = -1;
int tempCount = 1;

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void generate() {
    char a[30], b[30], result[30];
    char op = operators[topOp--];

    strcpy(b, operands[topVal--]);
    strcpy(a, operands[topVal--]);

    sprintf(result, "t%d", tempCount++);

    printf("%s = %s %c %s\n", result, a, op, b);

    strcpy(operands[++topVal], result);
}

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%99s", expr);

    printf("\nThree Address Code:\n");

    for (int i = 0; expr[i] != '\0';) {

        if (isalnum((unsigned char)expr[i])) {
            char token[30];
            int j = 0;

            while (isalnum((unsigned char)expr[i])) {
                token[j++] = expr[i++];
            }

            token[j] = '\0';
            strcpy(operands[++topVal], token);
        }

        else if (expr[i] == '(') {
            operators[++topOp] = expr[i++];
        }

        else if (expr[i] == ')') {
            while (topOp >= 0 && operators[topOp] != '(')
                generate();

            if (topOp >= 0)
                topOp--;

            i++;
        }

        else {
            char op = expr[i++];

            while (topOp >= 0 &&
                   operators[topOp] != '(' &&
                   precedence(operators[topOp]) >= precedence(op))
                generate();

            operators[++topOp] = op;
        }
    }

    while (topOp >= 0)
        generate();

    printf("\nFinal Result: %s\n", operands[topVal]);

    return 0;
}
