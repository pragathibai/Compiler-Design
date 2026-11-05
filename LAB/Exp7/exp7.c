
#include <stdio.h>

int main() {
    int nullableA = 1;
    int nullableB = 1;

    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> epsilon\n");
    printf("B -> epsilon\n");

    printf("\nFIRST sets:\n");

    // A and B produce epsilon
    if (nullableA)
        printf("FIRST(A) = { epsilon }\n");

    if (nullableB)
        printf("FIRST(B) = { epsilon }\n");

    // Find FIRST(S)
    printf("FIRST(S) = { ");

    if (nullableA)
        printf("a ");

    if (nullableB)
        printf("b ");

    printf("}\n");

    return 0;
}
