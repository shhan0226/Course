#include <stdio.h>
#include "lex.h"


#define MAXSTACK      1000         /* maximum size of stack */
#define InitStack     PushStack(0)
#define ContinueParse 1            /* loop parse again */
#define HaltParse     0            /* halt parse */

int token, tok;
int unflag = 0;
int get_token()
{
   if (unflag) {
      unflag = 0;
      return tok;
   }
   else {
      tok = yylex();
      return tok;
   }
}
void unget_token()
{
   unflag = 1;
}                 

extern void yyerror();
void yymsg();
int shift(), reduce(), accept(), error();

int sp = 0;
int stack[MAXSTACK];

struct prod_entry {
   char *production;               /* output of reduction */
   int offset_nonterminal;         /* column entry for nonterminal */
   int num_rightside;              /* number of symbols in RHS */
} prod[] = {
   {"accept", 0, 1},
   {"expr -> expr + term", 0, 3},
   {"expr -> term", 0, 1},
   {"term -> term * factor", 1, 3},
   {"term -> factor", 1, 1},
   {"factor -> ( expr )", 2, 3},
   {"factor -> TK_IDENTIFIER", 2, 1},
};

char msg[100];

struct table_entry {               /* action table */      
   int (*f)();                     /* function call for the action */
   int arg;                        /* parameter for the function */
} parse_table[][6] = {
/*    TK_IDENTIFIER TK_PLUS     TK_MULT     TK_LPAR     TK_RPAR     TK_EOF
-----------------------------------------------------------------------------*/
/* 0*/{{shift , 5},{error , 0},{error , 0},{shift , 4},{error , 0},{error , 0}},
/* 1*/{{error , 0},{shift , 6},{error , 0},{error , 0},{error , 0},{accept, 0}},
/* 2*/{{error , 0},{reduce, 2},{shift , 7},{error , 0},{reduce, 2},{reduce, 2}},
/* 3*/{{error , 0},{reduce, 4},{reduce, 4},{error , 0},{reduce, 4},{reduce, 4}},
/* 4*/{{shift , 5},{error , 0},{error , 0},{shift , 4},{error , 0},{error , 0}},
/* 5*/{{error , 0},{reduce, 6},{reduce, 6},{error , 0},{reduce, 6},{reduce, 6}},
/* 6*/{{shift , 5},{error , 0},{error , 0},{shift , 4},{error , 0},{error , 0}},
/* 7*/{{shift , 5},{error , 0},{error , 0},{shift , 4},{error , 0},{error , 0}},
/* 8*/{{error , 0},{shift , 6},{error , 0},{error , 0},{shift ,11},{error , 0}},
/* 9*/{{error , 0},{reduce, 1},{shift , 7},{error , 0},{reduce, 1},{reduce, 1}},
/*10*/{{error , 0},{reduce, 3},{reduce, 3},{error , 0},{reduce, 3},{reduce, 3}},
/*11*/{{error , 0},{reduce, 5},{reduce, 5},{error , 0},{reduce, 5},{reduce, 5}}
};

int goto_table[][3] = {            /* goto table */
/*        expr    term    factor   */
/*       ------  ------   ------   */
/*  0*/     1,      2,      3,
/*  1*/     0,      0,      0,
/*  2*/     0,      0,      0,
/*  3*/     0,      0,      0,
/*  4*/     8,      2,      3,
/*  5*/     0,      0,      0,
/*  6*/     0,      9,      3,
/*  7*/     0,      0,     10,
/*  8*/     0,      0,      0,
/*  9*/     0,      0,      0,
/* 10*/     0,      0,      0,
/* 11*/     0,      0,      0,
};

int offset[] = {                /* token entry action table */
/* TK_IDENTIFIER=0, TK_PLUS=1, TK_MULT=2 TK_LPAR=3, TK_RPAR=4, TK_EOF=5 */
    5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    0, 1, 2, 3, 4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};

void PushStack(int state)
{
   if (sp < MAXSTACK)
      stack[sp++] = state;
   else
      yyerror("system error: stack full, can't push");
} /* PushStack */
   
int PopStack()
{
   if (sp > 0)
      return stack[--sp];
   else
      yyerror("system error: stack empty");
} /* PopStack */

int TopOfStack()
{
   return stack[sp-1];
} /* TopOfStack */

parser()
{ 
   InitStack;
   get_token();
   while(1){
   
     int  a=(*parse_table[TopOfStack()][offset[tok]].f)(parse_table[TopOfStack()][offset[tok]].arg);
      
         if(a==0){
	    break;
	    }
      }
   
   
/* FILL IN THIS BLANK */
} /* parser */
   
int shift(int state)
{
   printf("shift %d \n",parse_table[TopOfStack()][offset[tok]].arg);
   PushStack(state);
   get_token();
  // printf("shift %d \n", parse_table[TopOfStack()][offset[tok]].arg);
/* FILL IN THIS BLANK */
   return ContinueParse;
} /* shift */

int reduce(int prodnum)
{
  printf("reduce %d",parse_table[TopOfStack()][offset[token]].arg);
  printf(" (%s) \n",prod[prodnum].production);
  switch(prod[prodnum].num_rightside){
     case 3:
       PopStack(); PopStack();PopStack();
       PushStack(goto_table[TopOfStack()][prod[prodnum].offset_nonterminal]);
     default:
       PopStack();
       PushStack(goto_table[TopOfStack()][prod[prodnum].offset_nonterminal]);
       }
/* FILL IN THIS BLANK */
   return ContinueParse;
} /* reduce */

int accept(int dummy)
{
   printf("accept\n");
/* FILL IN THIS BLANK */
   return HaltParse;
} /* accept */

int error(int error_handler)
{
   return ContinueParse;
} /* error */

void yymsg(char *msg)
{
   fprintf(stdout, "%s\n", msg);
} /* yymsg */
