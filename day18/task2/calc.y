%{
    #define YYSTYPE unsigned long long
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    int yylex(void);
    void yyerror(char *);
%}

%token INTEGER
%left '*'
%left '+'

%start program

%%

program:
	program_line program
	| 
	;

program_line:
	'\n'
	| statement '\n'
	| statement ';' program_line	
	;

statement:
        expr         		  { printf("%llu\n", $1); }
        ;

expr:
        INTEGER
        | expr '+' expr           { $$ = $1 + $3; }
        | expr '*' expr           { $$ = $1 * $3; }
        | '(' expr ')'            { $$ = $2; }
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
