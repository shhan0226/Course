%{
#define TK_ID    1
#define TK_NUM   2
#define TK_IF    3
#define TK_THEN  4
#define TK_ELSE  5
#define TK_RELOP 6

#define LT       7
#define LE       8
#define EQ       9
#define NE      10
#define GT      11
#define GE      12

int yylval;
%}

%%
%%

yywrap()
{
   return(1);
}

main(int argc, char *argv[])
{
   int n;

   if ((yyin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "can't open %s\n", argv[1]);
      exit(1) ;
   }

   n = yylex();
   while (n) {
      switch(n) {
         case TK_ID:
         case TK_NUM:
         case TK_IF:
         case TK_THEN:
         case TK_ELSE:
         case TK_RELOP:
      }
      n = yylex();
   }

   fclose(yyin);
}
