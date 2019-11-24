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
delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
number	{digit}+

%%
{ws}		{/* 아무것도 하지 않는다. 또 되돌려주지도 않는다. */}
if		{return(TK_IF);}
then 		{return(TK_THEN);}
else		{return(TK_ELSE);}
{id}		{/*yylval =*/ return(TK_ID);}
{number}	{/*yylval =*/return(TK_NUM);}
"<"		{yylval = LT; return(TK_RELOP);}
"<="		{yylval = LE; return(TK_RELOP);}
"="		{yylval = EQ; return(TK_RELOP);}
"<>"		{yylval = NE; return(TK_RELOP);}
">"		{yylval = GT; return(TK_RELOP);}
">="		{yylval = GE; return(TK_RELOP);}
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
	 	printf("TK_ID %s \n",yytext);
         	break;
	 case TK_NUM:
		printf("TK_NUM %d\n",atoi(yytext));
		break;
         case TK_IF:
	 	printf("TK_IF\n");
		break;
         case TK_THEN:
	 	printf("TK_THEN\n");
		break;
         case TK_ELSE:
	 	printf("TK_ELSE\n");
         case TK_RELOP:
	 	printf("TK_RELOP(%d)\n",yylval);
      		break;
      }
      n = yylex();
   }

   fclose(yyin);
}
