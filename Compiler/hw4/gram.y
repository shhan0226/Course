%{
#include <stdio.h>
#include <string.h>

#define prod0 "accept"
#define prod1 "expr -> expr + term"
#define prod2 "expr -> term"
#define prod3 "term -> term * factor"
#define prod4 "term -> factor"
#define prod5 "factor -> ( expr )"
#define prod6 "factor -> TK_NUM"

#define shift() yymesg("shift\n")
#define reduce(prod) yymesg("reduce (");yymesg(prod);yymesg(")\n")
#define accept() yymesg(prod0);yymesg("\n")

void yymesg();
%}

%token TK_NUM
%token TK_PLUS
%token TK_MULT
%token TK_LPAR
%token TK_RPAR

%start expr_p        /* start symbol is expr_p */
%%
expr_p  :  expr{ accept(); printf("result is %d\n", $1);}
	; 
expr    :  expr TK_PLUS{shift();} term  { $$ = $1 + $4; reduce(prod1);} 
        |  term {reduce(prod2); }
	;
term    :  term TK_MULT{shift();} factor { $$ = $1 * $4; reduce(prod3); }
        |  factor {reduce(prod4); }
	;
factor  : TK_LPAR{shift();} expr TK_RPAR{shift();} {$$ = $3; reduce(prod5); }
        | TK_NUM  {shift();}{ reduce(prod6); }
	;
/* Fill in this blank */

%%

void yymesg(char *msg)
{
   fprintf(stdout, "%s", msg);
} /* yymesg */
