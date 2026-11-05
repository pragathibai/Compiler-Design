
#include <stdio.h>
#include <string.h>

int main() {
    char lhs, production[10][50];
    char alpha[10][50], beta[10][50];
    int n, a = 0, b = 0;

    printf("Enter non-terminal: ");
    scanf(" %c", &lhs);

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (without spaces):\n");

    for (int i = 0; i < n; i++) {
        scanf("%49s", production[i]);

        if (production[i][0] == lhs) {
            strcpy(alpha[a++], production[i] + 1);
        } else {
            strcpy(beta[b++], production[i]);
        }
    }

    if (a == 0) {
        printf("\nNo left recursion found.\n");
    } else if (b == 0) {
        printf("\nCannot eliminate left recursion: no beta production.\n");
    } else {
        printf("\nGrammar after eliminating left recursion:\n");

        printf("%c -> ", lhs);
        for (int i = 0; i < b; i++) {
            printf("%s%c'", beta[i], lhs);
            if (i < b - 1)
                printf(" | ");
        }

        printf("\n%c' -> ", lhs);
        for (int i = 0; i < a; i++) {
            printf("%s%c'", alpha[i], lhs);
            printf(" | ");
        }
        printf("epsilon\n");
    }

    return 0;
}
