#ifndef lint
static char const 
yyrcsid[] = "$FreeBSD: src/usr.bin/yacc/skeleton.c,v 1.28 2000/01/17 02:04:06 bde Exp $";
#endif
#include <stdlib.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
static int yygrowstack();
#define YYPREFIX "yy"
#line 12 "gram.y"
#include <stdio.h>
#include <ctype.h>

#include "sym.h"

extern struct sym *symcreate();
extern remove2();

static char errmsg[512];

#define STRUCT_NESTING  16  /* how many levels of structure nesting are
                             * supported?
                             */

/* what is the base type at each of the active structure levels? */
static struct typestruct *basetype[STRUCT_NESTING];
static int str_nesting = 0; /* how many nested structure levels? */

static char *id_name;          /* points to id being defined */

struct sym *install_id();
extern struct typestruct *append_type();
extern struct sym *lookup();
void symprint();
#line 39 "gram.y"
typedef union {
   int                    i;
   char                  *s;
   struct typestruct     *t;
} YYSTYPE;
#line 48 "y.tab.c"
#define YYERRCODE 256
#define TK_IDENTIFIER 257
#define TK_NUM 258
#define TK_INT 259
#define TK_STRUCT 260
const short yylhs[] = {                                        -1,
    0,    1,    1,    3,    4,    4,    6,    6,    7,    7,
    9,    8,    8,   10,   11,   12,   12,   13,   14,   14,
   15,   15,   15,    5,    5,   16,   17,   17,   17,   17,
   17,    2,    2,   18,
};
const short yylen[] = {                                         2,
    2,    1,    2,    3,    1,    1,    3,    2,    3,    2,
    1,    1,    2,    3,    1,    1,    3,    2,    2,    0,
    1,    3,    4,    1,    3,    2,    1,    3,    3,    4,
    3,    1,    2,    2,
};
const short yydefred[] = {                                      0,
    5,   11,    0,    0,    2,    0,    6,    0,    0,    0,
    0,    3,   32,    0,    0,    0,   24,   15,    0,   12,
    0,    0,   10,   34,   33,   19,    4,    0,   27,    0,
    0,    7,   13,    0,   16,    0,    9,   25,    0,    0,
    0,   14,    0,   21,    0,    0,   28,   31,    0,   29,
   17,    0,    0,   30,   22,    0,   23,
};
const short yydgoto[] = {                                       3,
    4,   11,    5,    6,   15,    7,    8,   19,    9,   20,
   21,   34,   35,   16,   46,   17,   31,   13,
};
const short yysindex[] = {                                   -242,
    0,    0,    0, -238,    0,  -10,    0, -242, -115,  -26,
 -223,    0,    0,  -10,  -32,  -39,    0,    0, -119,    0,
  -10,  -87,    0,    0,    0,    0,    0,  -10,    0,  -10,
  -33,    0,    0,  -29,    0,  -37,    0,    0,   -6,   -2,
  -88,    0,  -10,    0,  -10,  -54,    0,    0,  -52,    0,
    0,    1, -215,    0,    0,  -49,    0,
};
const short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,  -36,    0,    0,    0,    0,
   45,    0,    0,  -36,    0,    0,    0,    0,    0,    0,
  -36,  -40,    0,    0,    0,    0,    0,  -36,    0,  -36,
  -31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -36,    0,  -36,  -30,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
const short yygindex[] = {                                      0,
    0,    0,   42,   12,    0,    0,    0,    0,    0,   28,
    0,    0,  -20,   -5,    0,   -4,    0,   37,
};
#define YYTABLESIZE 221
const short yytable[] = {                                       8,
   30,    8,   45,   20,   50,   32,   40,   23,   26,   26,
   18,   28,   26,   18,   43,   36,    1,    2,   10,   18,
    1,    2,   51,   38,   52,   39,   27,   26,   18,   42,
   18,   14,   24,   10,   47,   37,   53,   36,   48,   36,
   54,   55,   56,   57,    1,   12,   33,   25,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   41,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    2,   22,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   49,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    8,   29,    0,   44,
   20,
};
const short yycheck[] = {                                      40,
   40,   42,   40,   40,   93,  125,   40,  123,   14,   41,
   41,   44,   44,   44,   44,   21,  259,  260,  257,    8,
  259,  260,   43,   28,   45,   30,   59,   59,   59,   59,
   19,   42,   59,  257,   41,  123,   91,   43,   41,   45,
   93,   41,  258,   93,    0,    4,   19,   11,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
  260,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  257,   -1,  257,
  257,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 260
#if YYDEBUG
const char * const yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"TK_IDENTIFIER","TK_NUM","TK_INT","TK_STRUCT",
};
const char * const yyrule[] = {
"$accept : function",
"function : declarations exprs",
"declarations : declaration",
"declarations : declarations declaration",
"declaration : type_specifier declarator_list ';'",
"type_specifier : TK_INT",
"type_specifier : struct_specifier",
"struct_specifier : struct_def struct_declaration_list '}'",
"struct_specifier : struct TK_IDENTIFIER",
"struct_def : struct TK_IDENTIFIER '{'",
"struct_def : struct '{'",
"struct : TK_STRUCT",
"struct_declaration_list : struct_declaration",
"struct_declaration_list : struct_declaration_list struct_declaration",
"struct_declaration : stype struct_declarator_list ';'",
"stype : type_specifier",
"struct_declarator_list : struct_declarator",
"struct_declarator_list : struct_declarator_list ',' struct_declarator",
"struct_declarator : stars struct_declarator2",
"stars : '*' stars",
"stars :",
"struct_declarator2 : TK_IDENTIFIER",
"struct_declarator2 : '(' struct_declarator ')'",
"struct_declarator2 : struct_declarator2 '[' TK_NUM ']'",
"declarator_list : declarator",
"declarator_list : declarator_list ',' declarator",
"declarator : stars declarator2",
"declarator2 : TK_IDENTIFIER",
"declarator2 : '(' declarator ')'",
"declarator2 : declarator2 '[' ']'",
"declarator2 : declarator2 '[' TK_NUM ']'",
"declarator2 : declarator2 '(' ')'",
"exprs : expr",
"exprs : exprs expr",
"expr : TK_IDENTIFIER ';'",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
#line 373 "gram.y"
/* Install identifier in the symbol table with the type determined by
 * catenating builttype and basetype.
 */

struct sym *install_id(name, builttype, basetype)
    char *name;
    struct typestruct *builttype, *basetype;
{
    extern struct sym *symcreate();
    extern struct sym *vinstall();
    register struct sym *vp, *s;

    builttype = append_type(builttype, basetype);
    if (builttype->t_cat == strtype && builttype->t_size == 0)
       yyerror("unknown size");

    else {
       if (vp = lookup(name)) {
          sprintf(errmsg, "redeclaration of %s", name);
          yyerror(errmsg);
       }
       else {
          if (builttype->t_cat == arrtype && builttype->t_size == 0) {
             builttype->t_cat = ptrtype;
             builttype->t_size = 1;
          }
          vp = vinstall(symcreate(name, lvar, builttype));
       }
    }
    return vp;
}

/* Install a new field within a structure, making sure that this field
 * name does not conflict with existing field names.  Return the size
 * of the new field.
 */
struct_field(name, builttype, btype)
    char *name;
    struct typestruct *builttype, *btype;
{
    register struct sym *vp;
    register struct typestruct *tp;

    builttype = append_type(builttype, btype);
    if (builttype->t_cat == strtype && builttype->t_size == 0)
       yyerror("unknown size");

    tp = basetype[str_nesting-1];

    for (vp = tp->tt.t_first; vp; vp = vp->v_next)
       if (vp->v_name == name) {
          sprintf(errmsg, "redeclaration of %s", name);
          yyerror(errmsg);
          return 0;
       }

    if (builttype->t_cat == arrtype && builttype->t_size == 0) {
       builttype->t_cat = ptrtype;
       builttype->t_size = 1;
    }

    vp = symcreate(name, ivar, builttype);
    vp->v_next = tp->tt.t_first;
    if (tp->tt.t_first)
       vp->v_position = 
          tp->tt.t_first->v_position + tp->tt.t_first->v_type->t_size;
    else
       vp->v_position = 0;
    tp->tt.t_first = vp;
    return vp->v_type->t_size;
}

void symprint(sp)
   register struct sym *sp;
{
   register struct typestruct *vp;

   printf("%s: ", sp->v_name);
   vp = sp->v_type;
   while (vp) {
      switch (vp->t_cat) {
      case inttype:
         printf("int");
         break;
      case strtype:
         printf("str");
         printf("(%d)\n",vp->t_size);
         {
            register struct sym *sp = vp->tt.t_first;
            register i = 0;
            while (i < vp->t_size) {
               printf("   -> ");
               symprint(sp);
               i += sp->v_type->t_size;
               sp = sp->v_next;
            }
         }
         return;
         break;
      case arrtype:
         printf("arr");
         printf("(%d)",vp->t_size);
         break;
      case ptrtype:
         printf("ptr");
         break;
      case funtype:
         printf("fun");
         break;
      default:
         printf("unknown type");
         break;
      }
      vp = vp->tt.t_base;
      if (vp) printf(" -> ");
   }
   printf("\n");
}
#line 349 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack()
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss);
    if (newss == NULL)
        return -1;
    yyss = newss;
    yyssp = newss + i;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs);
    if (newvs == NULL)
        return -1;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYPARSE_PARAM
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG void
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif	/* ANSI-C/C++ */
#else	/* YYPARSE_PARAM */
#ifndef YYPARSE_PARAM_TYPE
#define YYPARSE_PARAM_TYPE void *
#endif
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL YYPARSE_PARAM_TYPE YYPARSE_PARAM;
#endif	/* ANSI-C/C++ */
#endif	/* ! YYPARSE_PARAM */

int
yyparse (YYPARSE_PARAM_ARG)
    YYPARSE_PARAM_DECL
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 5:
#line 63 "gram.y"
{
/* FILL IN THIS BLANK
- tinstall(inttype)
                     $<t>$ = ...
*/
                     yyval.t = tinstall(inttype, 1, NILTYPE);
                     basetype[str_nesting] = yyval.t;
                  }
break;
case 6:
#line 72 "gram.y"
{
                     yyval.t = yyvsp[0].t;
                  }
break;
case 7:
#line 82 "gram.y"
{
                     str_nesting--;
                     yyval.t = yyvsp[-2].t;
                     yyval.t->t_size = yyvsp[-1].i;
                  }
break;
case 8:
#line 88 "gram.y"
{
                     register struct sym *vp;

                     if (vp = struct_lookup(yyvsp[0].s))
                        yyval.t = vp->v_type;
                     else {
/* FILL IN THIS BLANK
- tinstall(strtype)
- struct_install(symcreate())
- tt.t_first : t_first struct name variable temporarily
               later points to variable representing first field (struct_field)
                        $<t>$ = ...
                        $<t>$->tt.t_first = ...
*/
                        yyval.t = tinstall(strtype, 0, NILTYPE);
                        yyval.t->tt.t_first = struct_install( symcreate(yyvsp[0].s ,yyvsp[-1].t->t_cat, yyval.t ) );
                     }
                  }
break;
case 9:
#line 111 "gram.y"
{
                     register struct sym *vp;  
 
                     if (vp = struct_lookup(yyvsp[-1].s)) {
                     /* if the current declarations is in the same scope
                      * as the existing declaration and the exiting
                      * declaration alreasy defined all of the fields,
                      * the gripe.
                      */
                        if (vp->v_type->t_size != 0) {
                           sprintf(errmsg, "redeclaration of %s", yyvsp[-1].s);
                           yyerror(errmsg);
                           yyval.t = tinstall(strtype, 0, NILTYPE);
                           yyval.t->t_size = 0;
                        }
                        else
                           yyval.t = vp->v_type;
                     }
                     else {    /* name not in structure table */
/* FILL IN THIS BLANK
- tinstall(strtype)
- struct_install(symcreate())
- tt.t_first : t_first struct name variable temporarily
               later points to variable representing first field (struct_field)
		        $<t>$ = ...
                        $<t>$->t_size = ...
                        $<t>$->tt.t_first = ... 
*/
		        yyval.t = tinstall(strtype, 0, NILTYPE);
                        yyval.t->t_size = 0;
                        yyval.t->tt.t_first = NULL;
                     }
                     basetype[str_nesting++] = yyval.t;
                  }
break;
case 10:
#line 146 "gram.y"
{
/* FILL IN THIS BLANK
- tinstall(strtype)
- struct_install(symcreate())
- tt.t_first : t_first struct name variable temporarily
               later points to variable representing first field (struct_field)
                     $<t>$ = ...
                     $<t>$->t_size = ...
                     $<t>$->tt.t_first = ...
*/
                     yyval.t = tinstall(strtype, 0, NILTYPE);
                     yyval.t->t_size = 0;
                     yyval.t->tt.t_first = NULL;
                     basetype[str_nesting++] = yyval.t;
                  }
break;
case 12:
#line 170 "gram.y"
{ yyval.i = yyvsp[0].i; }
break;
case 13:
#line 172 "gram.y"
{ yyval.i = yyvsp[-1].i + yyvsp[0].i; }
break;
case 14:
#line 178 "gram.y"
{ yyval.i = yyvsp[-1].i; }
break;
case 15:
#line 184 "gram.y"
{ basetype[str_nesting] = yyvsp[0].t; }
break;
case 16:
#line 190 "gram.y"
{
                     yyval.i = struct_field(id_name,yyvsp[0].t, basetype[str_nesting]);
                  }
break;
case 17:
#line 194 "gram.y"
{
                     yyval.i = yyvsp[-2].i
                          + struct_field(id_name, yyvsp[0].t, basetype[str_nesting]);
                  }
break;
case 18:
#line 205 "gram.y"
{
                     if (yyvsp[-1].i) {
                        int i;
                        struct typestruct *t = NILTYPE;
                        for (i = 0; i < yyvsp[-1].i; i++)
/* FILL IN THIS BLANK
- repeat tinstall(ptrtype)
- append_type(old,new)
                           t = ...
                        $<t>2 = ...
*/
                           t = append_type( t, tinstall(ptrtype, 1, NILTYPE));
                        yyvsp[0].t = append_type(yyvsp[0].t, t);
                     }
                     yyval.t = yyvsp[0].t;
                   }
break;
case 19:
#line 230 "gram.y"
{yyval.i = yyvsp[0].i+1;}
break;
case 20:
#line 236 "gram.y"
{yyval.i = 0;}
break;
case 21:
#line 244 "gram.y"
{
/* FILL IN THIS BLANK
- easy
                     id_name = ...
                     $<t>$ = ...
*/
                     id_name = yyvsp[0].s;
                     yyval.t = NILTYPE;
                  }
break;
case 22:
#line 254 "gram.y"
{
                     yyval.t = yyvsp[-1].t;
                  }
break;
case 23:
#line 258 "gram.y"
{ 
                     if (yyvsp[-1].i <= 0) {
                        yyerror("Negative dimension");
                        yyvsp[-1].i = 1;
                     }
/* FILL IN THIS BLANK
- tinstall(arrtype,-) see fix_size(csym.c)
- append_type
                     $<t>$ = ...
*/
                     yyval.t = append_type(yyvsp[-3].t, tinstall(arrtype, -yyvsp[-1].i, NILTYPE));
		  }
break;
case 24:
#line 275 "gram.y"
{
		      install_id(id_name, yyvsp[0].t, basetype[str_nesting]);
                   }
break;
case 25:
#line 279 "gram.y"
{ 
		      install_id(id_name, yyvsp[0].t, basetype[str_nesting]);
		   }
break;
case 26:
#line 289 "gram.y"
{
                     if (yyvsp[-1].i) {
                        int i;
                        struct typestruct *t = NILTYPE;

                        for (i = 0; i < yyvsp[-1].i; i++)
/* FILL IN THIS BLANK
- same as the above
                           t = ...
                        $<t>2 = ...
*/
                           t = append_type(t, tinstall(ptrtype, 1, NILTYPE) );
                        yyvsp[0].t = append_type(yyvsp[0].t, t);
                     }
                     yyval.t = yyvsp[0].t;
                   }
break;
case 27:
#line 312 "gram.y"
{
/* FILL IN THIS BLANK
- same as the above
	 	     id_name = ...
		     $<t>$ = ...
*/
	 	     id_name = yyvsp[0].s;
		     yyval.t = NILTYPE;
		  }
break;
case 28:
#line 322 "gram.y"
{
                      yyval.t = yyvsp[-1].t;
                  }
break;
case 29:
#line 326 "gram.y"
{
/* FILL IN THIS BLANK
- tinstall(ptrtype)
- append_type
		     $<t>$ = ...
*/
		     yyval.t = append_type(yyvsp[-2].t, tinstall(ptrtype, 1, NILTYPE));
		  }
break;
case 30:
#line 335 "gram.y"
{
                     if (yyvsp[-1].i <= 0) {
                       yyerror("Negative dimension");
                       yyvsp[-1].i = 1;
                     }
/* FILL IN THIS BLANK
- same as the above
		     $<t>$ = ...
*/
		     yyval.t = append_type(yyvsp[-3].t, tinstall(arrtype, -yyvsp[-1].i, NILTYPE));
		  }
break;
case 31:
#line 347 "gram.y"
{
/* FILL IN THIS BLANK
- tinstall(funtype,-1)
- append_type
		     $<t>$ = ...
*/
		     yyval.t = append_type(yyvsp[-2].t, tinstall(funtype, -1, NILTYPE));
		  }
break;
case 34:
#line 364 "gram.y"
{
                     register struct sym *sp = lookup(yyvsp[-1].s);

                     if (sp) symprint(lookup(yyvsp[-1].s));
                     else printf("%s: not declared\n", yyvsp[-1].s);
                  }
break;
#line 828 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
