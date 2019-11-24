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
   state=NextChar();
      switch(state) {
      
   case 'a' ... 'z' :
   	i=0;
	buf[i]=(char)state;
      if(state=='i'){
        state=NextChar();
	// forward=retract1;
         if(state=='n'){
            state=NextChar();
	  //  forward=retract1;
            if(state=='t'){
               state=NextChar();
	    //   forward=retract1;
               if(state==' '){
	 //	forward=retract1;

               	return 258;
	//	forward=retract1;
               }
            }
         }
      	 else if(state=='f'){
	 	forward=retract1;
	 	return 260;
	 }
      }
         
      if(state=='f'){
         state=NextChar();
         if(state=='l'){
            state=NextChar();
            if(state=='o'){
               state=NextChar();
               if(state=='a'){
                  state=NextChar();
                     if(state=='t'){
                        state=NextChar();
                        if(state=' '){
			   forward=retract1;
                           return 259;
                           }
                        }
                     }
                  }
               }
            }
     if(state=='e'){
        state=NextChar();
	if(state=='l'){
	  state=NextChar();
	   if(state=='s'){
	     state=NextChar();
	       if(state=='e'){
	         state=NextChar();
		   if(state==' '){
		     forward=retract1;
		     return 261;
		     }
		   }
		 }
	      }
	}
     printf("%c",state);    
     break;
   case '0' ... '9' :
	i=0;
	buf[i]=(char)state;
	while(1){
		i++;
		buf[i]=NextChar();
		if(buf[i]==';'||buf[i]=='.'){
			return 257;
		}
		else{
			break;
		}
	}




/*          i=0;
	  while(1){
	      buf[i]=state;
	      state=NextChar();
	      if(state=='0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'){
	        i++;
		buf[i]=state;
	      }
	      else// if(state==';'){
	      	forward=retract1;
	        return 257;
	     // }
          }*/
	    
     break;
   case '=':
      state=NextChar();
        if(state=='='){
		return 262;
		}
	else 
		return 268;
      break;
   case '(':
      return 263;
      break;
   case ')':
      return 264;
      break;
   case '{':
      return 265;
      break;
   case '}':
      return 266;
      break;
   case ',':
      return 267;
      break;
   case ';':
      return 269;
      break; 
   case '\0':
      return 270;
      break;
//      default:
//         printf("%c\n",state);
//   break;
   

      }   /* end of state */
   }      /* end of while */
}         /* end of function get_tok */

/* prints the current line, column error message */
void yyerror(char *msg)
{
   fprintf(stderr, "line:%3d, column:%3d %s\n", line, column, msg); 
}
