#include <stdio.h>

#define BufSize 8
#define Sentinel '\0'

static unsigned char buf[BufSize*2+1];
static unsigned char *lexeme_beginning, *forward;

#define NextChar() ((*forward)? *forward++:((forward=buf+BufSize+1),fillbuf(fp)))

static int tnl = 0, tnw = 0, tnc = 0;

static unsigned char fillbuf(FILE *fp)
{
   register unsigned char *i, *j;

   /* move the rest of token to the other buffer */
   i = lexeme_beginning;
   j = lexeme_beginning - BufSize;

   while (j <= forward)
      *(j++) = *(i++) ;

   lexeme_beginning -= BufSize;
   buf[BufSize + fread(buf+BufSize, 1, BufSize, fp)] = Sentinel;
   return buf[BufSize];
}

void countfile(FILE *fp, char *fname)
{
/* FILL IN THIS BLANK */
}

void printtotal()
{
   printf("%8d%8d%8d %s\n", tnl, tnw, tnc, "total");
}
