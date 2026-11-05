#include <stdio.h>
#include <string.h>

int main() {
    char p1[50], p2[50];
    int i = 0;

    printf("Enter first production: ");
    scanf("%49s", p1);

    printf("Enter second production: ");
    scanf("%49s", p2);

    while (p1[i] != '\0' && p2[i] != '\0' &&
           p1[i] == p2[i]) {
        i++;
    }

    if (i == 0) {
        printf("No common prefix found.\n");
    } else {
        printf("\nCommon prefix: ");
        for (int j = 0; j < i; j++)
            printf("%c", p1[j]);

        printf("\n\nFactored Grammar:\n");
        printf("S -> ");
        for (int j = 0; j < i; j++)
            printf("%c", p1[j]);
        printf("S' | a\n");

        printf("S' -> epsilon | ");
        printf("%s\n", p2 + i);
        printf("E -> b\n");
    }

    return 0;
}