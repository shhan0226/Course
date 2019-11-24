#include <stdio.h>
#include <stdlib.h>
#include "lex.h"

extern int get_tok();
extern int yylval,       /* integer value of TK_NUM */
           yylen;        /* length of TK_ID string */
extern char yytext[];    /* point to TK_ID string */

extern FILE *fin;

main(int argc, char *argv[])
{
   int n, i;
   char *pc;

   if (argc != 2) {
      fprintf(stderr, "usage: scan <input>\n");
      exit(1) ;
   }

   if ((fin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "can't open %s\n", argv[1]);
      exit(1) ;
   }

   n = get_tok();
   while (n != TK_EOF) {
      switch(n) {
         case TK_ID: printf("%s", "TK_ID: ");
            pc = yytext;
            for (i=0; i<yylen;i++)
               printf("%c",*pc++);
            printf("\n");
            break;
         case TK_NUM:  printf("%s", "TK_NUM: ");
            printf("%d\n",yylval);
            break;
         case TK_INT:        printf("%s\n", "TK_INT"); break;
         case TK_FLOAT:      printf("%s\n", "TK_FLOAT"); break;
         case TK_IF:         printf("%s\n", "TK_IF"); break;
         case TK_ELSE:       printf("%s\n", "TK_ELSE"); break;
         case TK_EQ:         printf("%s\n", "TK_EQ"); break;
         case TK_LPAR:       printf("%s\n", "TK_LPAR"); break;
         case TK_RPAR:       printf("%s\n", "TK_RPAR"); break;
         case TK_LBRACE:     printf("%s\n", "TK_LBRACE"); break;
         case TK_RBRACE:     printf("%s\n", "TK_RBRACE"); break;
         case TK_COMMA:     printf("%s\n", "TK_COMMA"); break;
         case TK_ASSIGN:     printf("%s\n", "TK_ASSIGN"); break;
         case TK_SCOLON:     printf("%s\n", "TK_SCOLON"); break;
      }
      n = get_tok();
   }
   printf("%s\n", "TK_EOF");

   fclose(fin);
}

