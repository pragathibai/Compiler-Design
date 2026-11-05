
#include <stdio.h>
#include <string.h>

#define N 6

char lhs[N] = {'E', 'E', 'T', 'T', 'F', 'F'};

char rhs[N][20] = {
    "E+T",
    "T",
    "T*F",
    "F",
    "(E)",
    "i"
};

char trailing[3][20];
int count[3] = {0};

int getIndex(char ch) {
    if (ch == 'E') return 0;
    if (ch == 'T') return 1;
    if (ch == 'F') return 2;
    return -1;
}

int addTrailing(int index, char ch) {
    for (int i = 0; i < count[index]; i++) {
        if (trailing[index][i] == ch)
            return 0;
    }

    trailing[index][count[index]++] = ch;
    return 1;
}

int main() {
    int changed;

    do {
        changed = 0;

        for (int i = 0; i < N; i++) {
            int index = getIndex(lhs[i]);
            int len = strlen(rhs[i]);

            char last = rhs[i][len - 1];
            int lastIndex = getIndex(last);

            if (lastIndex == -1) {
                changed |= addTrailing(index, last);
            }
            else {
                if (len >= 2) {
                    char previous = rhs[i][len - 2];

                    if (getIndex(previous) == -1) {
                        changed |= addTrailing(index, previous);
                    }
                }

                for (int j = 0; j < count[lastIndex]; j++) {
                    changed |= addTrailing(
                        index, trailing[lastIndex][j]
                    );
                }
            }
        }

    } while (changed);

    printf("\nTRAILING Sets:\n");

    for (int i = 0; i < 3; i++) {
        printf("TRAILING(%c) = { ", "ETF"[i]);

        for (int j = 0; j < count[i]; j++) {
            if (trailing[i][j] == 'i')
                printf("id ");
            else
                printf("%c ", trailing[i][j]);
        }

        printf("}\n");
    }

    return 0;
}
