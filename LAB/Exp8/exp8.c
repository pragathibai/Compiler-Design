
#include <stdio.h>
#include <string.h>

#define MAX 20

char production[10][MAX] = {
    "AaAb",
    "BbBa",
    ""
};

char nonterminals[] = {'S', 'A', 'B'};
char follow[3][MAX];
int count[3] = {0};

int getIndex(char ch) {
    for (int i = 0; i < 3; i++) {
        if (nonterminals[i] == ch)
            return i;
    }
    return -1;
}

void addFollow(int index, char ch) {
    if (index == -1)
        return;

    for (int i = 0; i < count[index]; i++) {
        if (follow[index][i] == ch)
            return;
    }

    follow[index][count[index]++] = ch;
    follow[index][count[index]] = '\0';
}

int main() {
    int changed;

    strcpy(follow[0], "$");
    count[0] = 1;

    do {
        changed = 0;

        for (int p = 0; p < 2; p++) {
            char lhs = 'S';
            char *rhs = production[p];

            for (int i = 0; rhs[i] != '\0'; i++) {
                int index = getIndex(rhs[i]);

                if (index != -1) {
                    int oldCount = count[index];

                    if (rhs[i + 1] != '\0') {
                        if (getIndex(rhs[i + 1]) == -1)
                            addFollow(index, rhs[i + 1]);
                    } else {
                        int lhsIndex = getIndex(lhs);
                        for (int j = 0; j < count[lhsIndex]; j++)
                            addFollow(index, follow[lhsIndex][j]);
                    }

                    if (count[index] != oldCount)
                        changed = 1;
                }
            }
        }

        // FOLLOW(A) and FOLLOW(B) also receive
        // terminals following them in productions.

        int oldA = count[1];
        int oldB = count[2];

        addFollow(1, 'a');
        addFollow(1, 'b');
        addFollow(2, 'a');
        addFollow(2, 'b');

        if (count[1] != oldA || count[2] != oldB)
            changed = 1;

    } while (changed);

    printf("FOLLOW Sets:\n");

    for (int i = 0; i < 3; i++) {
        printf("FOLLOW(%c) = { ", nonterminals[i]);

        for (int j = 0; j < count[i]; j++)
            printf("%c ", follow[i][j]);

        printf("}\n");
    }

    return 0;
}
