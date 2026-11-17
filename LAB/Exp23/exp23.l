
%{
#include <stdio.h>

int line = 1;
%}

%%

[^\n]*\n {
    printf("%3d\t%s", line++, yytext);
}

[^\n]+ {
    printf("%3d\t%s\n", line++, yytext);
}

%%

int main()
{
    extern FILE *yyin;

    yyin = fopen("sample.c", "r");

    if (yyin == NULL) {
        printf("Error opening sample.c\n");
        return 1;
    }

    printf("C Program with Line Numbers:\n\n");

    yylex();

    fclose(yyin);
    return 0;
}

int yywrap()
{
    return 1;
}
