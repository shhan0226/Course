#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;       /* input stream */

int yyparse();

main(argc, argv)
   register int argc;
   register char *argv[];
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
   yyparse();

   fclose(yyin);
}
