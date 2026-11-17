
%{
#include <stdio.h>
int count = 0;
%}

%%

"<"[^>\n]+">" {
    printf("HTML Tag: %s\n", yytext);
    count++;
}

\n      ;
.       ;

%%

int main()
{
    extern FILE *yyin;

    yyin = fopen("sample.html", "r");

    if (yyin == NULL) {
        printf("Error opening sample.html\n");
        return 1;
    }

    printf("HTML Tags in the Input File:\n\n");

    yylex();

    printf("\nTotal Number of HTML Tags: %d\n", count);

    fclose(yyin);
    return 0;
}

int yywrap()
{
    return 1;
}
