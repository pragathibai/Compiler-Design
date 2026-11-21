
%{
#include <stdio.h>
int count = 0;
%}

%%

[A-Z]+ {
    printf("Capital Word: %s\n", yytext);
    count++;
}

[a-zA-Z0-9_]+ ;
[ \t\n]+ ;

. ;

%%

int main()
{
    extern FILE *yyin;

    yyin = fopen("input.txt", "r");

    if (yyin == NULL) {
        printf("Cannot open input.txt\n");
        return 1;
    }

    printf("Capital Words in the Input:\n\n");

    yylex();

    printf("\nTotal Capital Words: %d\n", count);

    fclose(yyin);
    return 0;
}

int yywrap()
{
    return 1;
}
