
%{
#include <stdio.h>
%}

%%

[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,} {
    printf("Valid Email Address\n");
}

[^ \t\n]+ {
    printf("Invalid Email Address\n");
}

[ \t\n]+ ;

%%

int main()
{
    printf("Enter an email address: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
