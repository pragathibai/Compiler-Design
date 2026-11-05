
#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int S() {
    if (input[pos] == 'a') {
        pos++;

        if (S()) {
            if (input[pos] == 'b') {
                pos++;
                return 1;
            }
            return 0;
        }
        return 0;
    }

    // S -> epsilon
    return 1;
}

int main() {
    printf("Grammar: S -> aSb | epsilon\n");

    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    pos = 0;

    if (S() && input[pos] == '\0')
        printf("\nString is ACCEPTED by the grammar.\n");
    else
        printf("\nString is REJECTED by the grammar.\n");

    return 0;
}
