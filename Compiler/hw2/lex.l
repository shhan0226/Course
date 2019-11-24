%{
#include <stdio.h>
#include <string.h>
#include "lex.h"

static int linenumber = 1, columnnumber = 0;
static int count();
static int comment();
static int invalid_char();

char err_msg[30];      /* error message buffer */
int yylval, yylen;
%}

delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
number	{digit}+



%%
if           {count(); return (TK_IF);}
else         {count(); return (TK_ELSE);}
int          {count(); return (TK_ID);}
float        {count(); return (TK_FLOAT);}
{ws}         {count();}
{number}     {count(); yylval = atoi(yytext);  return (TK_NUM);}
{id}         {count(); yylen = strlen(yytext); return (TK_ID);}
"=="         {count(); return (TK_EQ);}
"="	     {count(); return (TK_ASSIGN);}
";"          {count(); return (TK_SCOLON);}
","          {count(); return (TK_COMMA);}
"("          {count(); return (TK_LPAR);}
")"          {count(); return (TK_RPAR);}
"{"          {count(); return (TK_LBRACE);}
"}"          {count(); return (TK_RBRACE);}
"/*"         {comment();}
"*/"         {comment();}
.            {count(); invalid_char();}

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
         columnnumber = 0;
      }
      else if(yytext[i] == '\t')
         columnnumber += 8 - (columnnumber%8);
      else columnnumber++;
}

/* read remainder of comments */
static int comment()
{
   char c;

   c = input();
   do {
      unput(c);
      while((c=input()) != '*')
         if (c =='\n'){
            linenumber++;
            columnnumber = 0;
         }
         else if (c =='\t')
            columnnumber += 8 - (columnnumber%8);
         else columnnumber++;
      columnnumber++;    /* count the closing '*' */
   } while((c=input()) != '/');
   columnnumber++;       /* count the closing '/' */
}

static int invalid_char()
{
   sprintf(err_msg, "invalid character: 0x%x", yytext[0]);
   yyerror(err_msg);
}
