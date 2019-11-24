#ifndef YYERRCODE
#define YYERRCODE 256
#endif

#define TK_IDENTIFIER 257
#define TK_NUM 258
#define TK_INT 259
#define TK_STRUCT 260
typedef union {
   int                    i;
   char                  *s;
   struct typestruct     *t;
} YYSTYPE;
extern YYSTYPE yylval;
