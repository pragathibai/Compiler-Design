
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

char leading[3][20];
int count[3] = {0};

int getIndex(char ch) {
    if (ch == 'E') return 0;
    if (ch == 'T') return 1;
    if (ch == 'F') return 2;
    return -1;
}

int addLeading(int index, char ch) {
    for (int i = 0; i < count[index]; i++) {
        if (leading[index][i] == ch)
            return 0;
    }

    leading[index][count[index]++] = ch;
    return 1;
}

int main() {
    int changed;

    do {
        changed = 0;

        for (int i = 0; i < N; i++) {
            int index = getIndex(lhs[i]);
            char first = rhs[i][0];

            if (getIndex(first) == -1) {
                changed |= addLeading(index, first);
            }
            else {
                int nextIndex = getIndex(first);

                if (rhs[i][1] != '\0' &&
                    getIndex(rhs[i][1]) == -1) {
                    changed |= addLeading(index, rhs[i][1]);
                }

                for (int j = 0; j < count[nextIndex]; j++) {
                    changed |= addLeading(index,
                                          leading[nextIndex][j]);
                }
            }
        }

    } while (changed);

    printf("\nLEADING Sets:\n");

    for (int i = 0; i < 3; i++) {
        printf("LEADING(%c) = { ", "ETF"[i]);

        for (int j = 0; j < count[i]; j++) {
            if (leading[i][j] == 'i')
                printf("id ");
            else
                printf("%c ", leading[i][j]);
        }

        printf("}\n");
    }

    return 0;
}
