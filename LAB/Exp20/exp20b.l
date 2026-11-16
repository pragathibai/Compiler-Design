
%{
#include <stdio.h>

int macro_count = 0;
int header_count = 0;
%}

%%

^[ \t]*#[ \t]*define[ \t]+[A-Za-z_][A-Za-z0-9_]* {
    macro_count++;
}

^[ \t]*#[ \t]*include[ \t]*[<"][^>"]+[>"] {
    header_count++;
}

\n      ;
.       ;

%%

int main()
{
    extern FILE *yyin;

    yyin = fopen("sample.c", "r");

    if (yyin == NULL) {
        printf("Cannot open sample.c\n");
        return 1;
    }

    yylex();

    printf("\nPreprocessor Directive Analysis:\n");
    printf("Number of Macros Defined: %d\n", macro_count);
    printf("Number of Header Files Included: %d\n", header_count);

    fclose(yyin);
    return 0;
}

int yywrap()
{
    return 1;
}
