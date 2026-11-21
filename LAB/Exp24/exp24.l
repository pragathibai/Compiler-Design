
%{
#include <stdio.h>

FILE *out;
int comment_lines = 0;
%}

%x BLOCK

%%

"//"[^\n]* {
    comment_lines++;
}

"/*" {
    comment_lines++;
    BEGIN(BLOCK);
}

<BLOCK>"*/" {
    BEGIN(INITIAL);
}

<BLOCK>\n {
    comment_lines++;
    fputc('\n', out);
}

<BLOCK>. ;

\"([^\\\n]|\\.)*\" {
    fputs(yytext, out);
}

\'([^\\\n]|\\.)*\' {
    fputs(yytext, out);
}

\n {
    fputc('\n', out);
}

. {
    fputs(yytext, out);
}

%%

int main()
{
    extern FILE *yyin;

    yyin = fopen("input.c", "r");

    if (yyin == NULL) {
        printf("Cannot open input.c\n");
        return 1;
    }

    out = fopen("output.c", "w");

    if (out == NULL) {
        printf("Cannot create output.c\n");
        fclose(yyin);
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(out);

    printf("\nComment lines removed: %d\n", comment_lines);
    printf("Comments eliminated successfully.\n");
    printf("Cleaned program saved in output.c\n");

    return 0;
}

int yywrap()
{
    return 1;
}
