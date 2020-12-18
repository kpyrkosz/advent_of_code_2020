%{
#include <stdlib.h>
void yyerror(char *);
#include "calc.tab.h"
%} 

%%

[0-9]+      { 
                yylval = strtoull(yytext, NULL, 10); 
                return INTEGER;
            }
[()-+*\n]  return *yytext; 
[ \t]       ; 
.           {yyerror("invalid character"); }

%%

int yywrap()
{
return 1;
}	
