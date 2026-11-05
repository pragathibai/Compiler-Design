#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[100];
int pos = 0;

void E();
void E1();
void T();
void T1();
void F();

void error() {
    printf("Invalid Expression!\n");
    exit(0);
}

void E() {
    T();
    E1();
}

void E1() {
    if (input[pos] == '+') {
        pos++;
        T();
        E1();
    }
}

void T() {
    F();
    T1();
}

void T1() {
    if (input[pos] == '*') {
        pos++;
        F();
        T1();
    }
}

void F() {
    if (isalpha((unsigned char)input[pos])) {
        pos++;
    }
    else if (input[pos] == '(') {
        pos++;
        E();

        if (input[pos] == ')')
            pos++;
        else
            error();
    }
    else {
        error();
    }
}

int main() {
    printf("Grammar:\n");
    printf("E  -> T E'\n");
    printf("E' -> + T E' | epsilon\n");
    printf("T  -> F T'\n");
    printf("T' -> * F T' | epsilon\n");
    printf("F  -> ( E ) | id\n");

    printf("\nEnter an expression: ");
    scanf("%99s", input);

    E();

    if (input[pos] == '\0')
        printf("\nExpression is ACCEPTED.\n");
    else
        printf("\nExpression is REJECTED.\n");

    return 0;
}
