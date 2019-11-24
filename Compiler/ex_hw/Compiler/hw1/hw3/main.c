#include <stdio.h>
#include <stdlib.h>
#include "lex.h"

extern void expr();

extern FILE *yyin;       /* input stream */

extern int yylval,       /* integer value of TK_ICONSTANT */
	   yylen;        /* length of TK_IDENTIFIER string */

extern char *yytext;    /* point to TK_IDENTIFIER string */

main(register int argc, register char *argv[])
{
   int n, i;
   char *c;

   if (argc != 2) {
      fprintf(stderr, "usage: parser <input>\n");
      exit(1) ;
   }

   if ((yyin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "can't open %s\n", argv[1]);
      exit(1) ;
   }
   expr();

   fclose(yyin);
}
