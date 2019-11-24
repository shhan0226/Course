%{
#include <stdio.h>
#include <string.h>
#include "lex.h"

static int linenumber = 1, columnnumber = 0;
static int count();
static int identifier();
static int bad_char();

char err_msg[30];      /* error message buffer */
int yylval, yylen;
%}

letter [a-zA-Z]
digit  [0-9]
ws     [ \t\n]
id     ({letter}|_)({letter}|{digit}|_)*
number {digit}+

%%

{ws}                {count();}
{id}                {count();return identifier();}
"+"                 {count();return TK_PLUS;}
"*"                 {count();return TK_MULT;}
"("                 {count();return TK_LPAR;}
")"                 {count();return TK_RPAR;}
.                   {bad_char();}
%%
yywrap()
{
   return(1);
}

/* prints the current line, column error message */
void yyerror(msg)
   char *msg;
{
   fprintf(stderr, "line:%3d, column:%3d %s\n", linenumber, columnnumber, msg); 
}

/* keep column numbers correct */
static int count()
{
   int i;

   for(i = 0; yytext[i] != '\0'; i++)
      if(yytext[i] == '\n') {
         linenumber++;
         columnnumber=0;
      }
      else if(yytext[i] == '\t')
         columnnumber +=8 - (columnnumber % 8);
      else columnnumber++;
}

static int identifier()
{
   yylen = strlen(yytext);
   return TK_IDENTIFIER;
}

static int bad_char()
{
   sprintf(err_msg, "invalid character: 0x%x", yytext[0]);
   yyerror(err_msg);
}
