
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[500];
    int vowels = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = tolower((unsigned char)sentence[i]);

        if (ch == 'a' || ch == 'e' ||
            ch == 'i' || ch == 'o' ||
            ch == 'u') {
            vowels++;
        }
    }

    printf("\nNumber of vowels: %d\n", vowels);

    return 0;
}
