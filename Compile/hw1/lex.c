#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lex.h"

#define BufSize  1024
#define Sentinel '\0'

#define Space    ' '
#define Tab      '\t'
#define Newline  '\n'

#define MAX_MSG  30   /* maximum size of an error message */
#define MAX_BUF  80   /* maximum size of an identifier */

static unsigned char buf[2*BufSize + 1];

static unsigned char *lexeme_beginning, *forward;

static int line = 1, column = 0;

#define retract1 forward--

#define NextChar() ((*forward)? *forward++:((forward=buf+BufSize+1),fillbuf()))

/*initial status when getting token */
static int IsFirst = 1;

int yylval, yylen;
char yytext[MAX_BUF];

void yyerror();
char err_msg[MAX_MSG];      /* error message buffer */

FILE *fin;

static unsigned char fillbuf()
{
   register unsigned char *i, *j;

   /* when two buffers overflow, issue error messsage and abort program */
   if (lexeme_beginning == buf) {
      printf("Buffer overflow error\n");
      exit(0);
   }

   /* move the rest of token to the other buffer */
   i = lexeme_beginning;
   j = lexeme_beginning - BufSize;

   while (j < forward-1)
      *(j++) = *(i++) ; 

   lexeme_beginning -= BufSize;

   buf[BufSize + fread(buf+BufSize, 1, BufSize, fin)] = Sentinel;

   return buf[BufSize];        /* end of buffer */
}

/* gets the next token from input stream */
int get_tok()
{

char next_state[]={
//  1  2  3  4  5  6  7  8  9 10    11 12 13 14 15 16 17 18 19 20
 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //0~ 20
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 18, //21 ~40
    19, 0, 0, 22, 0, 0, 24, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 0, 23, 0, //41 ~60
    16, 0, 0, 0, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, //61 ~80
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, //81 ~100
    12, 7, 1, 1, 3, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, //101 ~ 120
    1, 1, 20, 0, 21, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //121 ~ 140
    
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //~ 160
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //~ 180
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //~ 200
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //~ 220
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //~ 240
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //~ 260
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //~ 280

};


   register unsigned char c, *pc;
   register int state = 0;
   register int i;

   /* check whether initial or not */
   if (IsFirst) {
      buf[2*BufSize] = Sentinel;
      forward = buf + 2*BufSize;
      IsFirst = 0;
   }

   lexeme_beginning = forward;

   /* until pattern match, repeat */
   while(1) {
      switch(state) {

/* FILL IN THIS BLANK */
      case 0: yylval =0;
              c = NextChar();
              column++;
              if(c == Space){
                lexeme_beginning++;
              }
              else if(c ==Tab){
                column += 7 - (column%8);
                lexeme_beginning++;
              }
              else if (c == Newline){
                 line++;
                 column =0;
                 lexeme_beginning++;
              }
              else if( next_state[c] ==0){
                 sprintf(err_msg, "invalid char : 0x%x",c);
                 yyerror(err_msg);
                 lexeme_beginning++;
              }
              else state = next_state[c];
              break;

       case 1: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    yylen = forward - lexeme_beginning;
                    pc = (char*) lexeme_beginning;
                    for(i =0; i < yylen; i++)
                        yytext[i] = *pc++;
                    return(TK_ID);
               }
               break;

       case 2: yylval = yylval *10 + c -'0';
                c = NextChar();
                column++;
                if (isdigit(c))state =2;
                else {
                      retract1;
                      column--;
                      return(TK_NUM);
                }
                break;

               
       case 3: c = NextChar();
               column++;
               if( c == 'f') state = 4;
               else if( c == 'n') state = 5;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;

       case 4: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return(TK_IF);
               }
               break;


       case 5: c = NextChar();
               column++;
               if( c == 't') state = 6;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;

       case 6: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return(TK_INT);
               }
               break;


       case 7: c = NextChar();
               column++;
               if( c == 'l') state = 8;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;

       case 8: c = NextChar();
               column++;
               if( c == 'o') state = 9;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;

       case 9: c = NextChar();
               column++;
               if( c == 'a') state = 10;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;

       case 10: c = NextChar();
               column++;
               if( c == 't') state = 11;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;
       
       case 11: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_FLOAT);  
               }
               break;


       case 12: c = NextChar();
               column++;
               if( c == 'l') state = 13;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;

       case 13: c = NextChar();
               column++;
               if( c == 's') state = 14;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;

       case 14: c = NextChar();
               column++;
               if( c == 'e') state = 15;
               else if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    state = 1;
               }
               break;

       case 15: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_ELSE);
               }
               break;


       case 16: c = NextChar();
               column++;
               if( c == '=')state =17;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_ASSIGN);
               }
               break;

       case 17: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_EQ);
               }
               break;

        case 18: return (TK_LPAR);

    /*   case 18: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_LPAR);
               }
               break;
*/
       case 19: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_RPAR);
               }
               break;

        case 20: return (TK_LBRACE);

/*       case 20: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_LBRACE);
               }
               break;
*/

       case 21: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_RBRACE);
               }
               break;

       case 22: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_COMMA);
               }
               break;

       case 23: c = NextChar();
               column++;
               if( isalnum(c) ) state = 1;
               else{
                    retract1;
                    column--;
                    return (TK_SCOLON);
               }
               break;

	case 24: c = NextChar();
                column++;
                lexeme_beginning++;
                if( c == '*') state = 25;
                else state =  24;
                break;
              
        case 25: c = NextChar();
                column++;
                lexeme_beginning++;
                if( c == '*' ) state = 26;
                else state = 25;
                break;

        case 26: c = NextChar();
                column++;
                lexeme_beginning++;
                if (c == '/') state = 0;
                else state =  25; 
                break;

        case 27: return (TK_EOF);
               break;



      }   /* end of state */
   }      /* end of while */
}         /* end of function get_tok */

/* prints the current line, column error message */
void yyerror(char *msg)
{
   fprintf(stderr, "line:%3d, column:%3d %s\n", line, column, msg); 
}
