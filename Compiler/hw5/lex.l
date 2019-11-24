%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

static int linenumber = 1, columnnumber = 0;
static int count();
static int identifier();
static int constant();
static int bad_char();

char err_msg[30];      /* error message buffer */
int yylen;
%}

letter [a-zA-Z]
digit  [0-9]
ws     [ \t\n]
id     ({letter}|_)({letter}|{digit}|_)*
number {digit}+

%%

int                 {count(); return TK_INT;}
struct              {count(); return TK_STRUCT;}
{ws}                {count();}
{id}                {count(); return identifier();}
{number}            {count(); return constant();}
";"                 {count(); return (';');}
","                 {count(); return (',');}
"{"                 {count(); return ('{');}
"}"                 {count(); return ('}');}
"["                 {count(); return ('[');}
"]"                 {count(); return (']');}
"("                 {count(); return ('(');}
")"                 {count(); return (')');}
"*"                 {count(); return ('*');}
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
   char *slookup();

   yylval.s = slookup(yytext, 1);
   return TK_IDENTIFIER;
}

static int constant()
{
   yylval.i=atoi(yytext);
   return(TK_NUM);
}


static int bad_char()
{
   sprintf(err_msg, "invalid character: 0x%x", yytext[0]);
   yyerror(err_msg);
}
