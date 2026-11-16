
%{
#include <stdio.h>
%}

DIGIT   [0-9]
EXP     [eE][+-]?{DIGIT}+
FLOAT   (({DIGIT}+\.{DIGIT}*|\.{DIGIT}+){EXP}?|{DIGIT}+{EXP})
INT     (0[xX][0-9a-fA-F]+|{DIGIT}+)
ID      [A-Za-z_][A-Za-z0-9_]*

%x COMMENT

%%

"//"[^\n]*              ;
"/*"                    BEGIN(COMMENT);
<COMMENT>"*/"           BEGIN(INITIAL);
<COMMENT>\n             ;
<COMMENT>.              ;

\"([^\\\n]|\\.)*\"      ;
\'([^\\\n]|\\.)*\'      ;

{FLOAT}                 {
                            printf("Constant: %s\n", yytext);
                        }

{INT}                   {
                            printf("Constant: %s\n", yytext);
                        }

{ID}                    ;
[ \t\n]+                ;
.                       ;

%%

int main()
{
    extern FILE *yyin;

    yyin = fopen("sample.c", "r");

    if (yyin == NULL) {
        printf("Cannot open sample.c\n");
        return 1;
    }

    printf("Constants in the C program:\n\n");
    yylex();

    fclose(yyin);
    return 0;
}

int yywrap()
{
    return 1;
}
