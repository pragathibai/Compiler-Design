
%{
#include <stdio.h>
#include <string.h>

int characters = 0;
int words = 0;
int lines = 0;
int last_char = '\n';
int has_content = 0;
%}

%x COMMENT

%%

"//"[^\n]*       ;

"/*"             BEGIN(COMMENT);

<COMMENT>"*/"    BEGIN(INITIAL);
<COMMENT>\n      { lines++; last_char = '\n'; has_content = 1; }
<COMMENT>.       ;

\"([^\\\n]|\\.)*\" {
                     characters += yyleng;
                     words++;
                     last_char = yytext[yyleng-1];
                     has_content = 1;
                   }

\'([^\\\n]|\\.)*\' {
                     characters += yyleng;
                     words++;
                     last_char = yytext[yyleng-1];
                     has_content = 1;
                   }

[A-Za-z_][A-Za-z0-9_]* {
                     characters += yyleng;
                     words++;
                     last_char = yytext[yyleng-1];
                     has_content = 1;
                   }

[0-9]+             {
                     characters += yyleng;
                     words++;
                     last_char = yytext[yyleng-1];
                     has_content = 1;
                   }

[ \t\r]+           ;

\n                 {
                     lines++;
                     last_char = '\n';
                     has_content = 1;
                   }

.                  {
                     characters++;
                     last_char = yytext[0];
                     has_content = 1;
                   }

%%

int main() {
    extern FILE *yyin;

    yyin = fopen("sample.c", "r");

    if (yyin == NULL) {
        printf("Error: Cannot open sample.c\n");
        return 1;
    }

    yylex();

    if (has_content && last_char != '\n')
        lines++;

    printf("\nLexical Analysis Results\n");
    printf("------------------------\n");
    printf("Number of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);

    fclose(yyin);
    return 0;
}

int yywrap() {
    return 1;
}
