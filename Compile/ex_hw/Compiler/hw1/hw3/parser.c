#include <stdio.h>
#include "lex.h"

#define errmsg "syntax error"

#define prod1  "expr -> term expr_p"
#define prod2  "expr_p -> + term expr_p"
#define prod3  "expr_p -> epsilon"
#define prod4  "term -> factor term_p"
#define prod5  "term_p -> * factor term_p"
#define prod6  "term_p -> epsilon"
#define prod7  "factor -> TK_IDENTIFIER"
#define prod8  "factor -> ( expr )"

extern void yyerror();
void yymsg();

void expr();
void expr_p();
void term();
void term_p();
void factor();

int token;
int unflag = 0;

int get_token()
{
   if (unflag) { 
      unflag = 0;
      return token;
   }
   else return yylex();
}
void unget_token()
{
   unflag = 1;
}

void expr()
{
   switch(token = get_token()) {
      case TK_IDENTIFIER: case TK_LPAR:
         unget_token();
         yymsg(prod1);
         term();
         expr_p();
         return;
      case TK_RPAR: case TK_EOF:
         unget_token();
         yyerror(errmsg);
         return;
   }
} /* expr */

void expr_p()
{
   switch(token = get_token()){
      case TK_PLUS:
       // unget_token();
        yymsg(prod2);
	term();
	expr_p();
	return;
      case TK_EOF: case TK_RPAR:
        unget_token();
	yymsg(prod3);
      return;
   
  }
/* FILL IN THIS BLANK */
} /* expr_p */

void term()
{
   switch(token = get_token()){
       case TK_IDENTIFIER: case TK_LPAR:
         unget_token();
         yymsg(prod4);
         factor();
         term_p();
         return;
      case TK_RPAR: case TK_EOF:
         unget_token();
	 yyerror(errmsg);
	 return;
   }
/* FILL IN THIS BLANK */
} /* term */

void term_p()
{
   switch(token = get_token()){
      case TK_MULT:
         //unget_token();
	 yymsg(prod5);
	 factor();
	 term_p();
	 return;
      case TK_PLUS: case TK_RPAR: case TK_EOF:
         unget_token();
	 yymsg(prod6);
	 return;
   }
/* FILL IN THIS BLANK */
} /* term_p */
void factor()
{
   switch(token = get_token()){
      case TK_IDENTIFIER:
	 yymsg(prod7);
	 return;
      case TK_PLUS: case TK_MULT: case TK_RPAR: case TK_EOF:
         unget_token();
	 yyerror(errmsg);
	 return;
      case TK_LPAR:
	 yymsg(prod8);
	 expr();
	 if(token!=TK_RPAR){
	    yyerror(errmsg);
	 }
	 return;
   }
/* FILL IN THIS BLANK */
} /* factor */

/* print a message of the procduction which is being applied */
void yymsg(msg)
   char *msg;
{
   printf("%s\n",msg);
} /* yymsg */
