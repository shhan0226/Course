#include <stdio.h>

#define BufSize 8
#define Sentinel '\0'

static unsigned char buf[BufSize*2+1];
static unsigned char *lexeme_beginning, *forward;


// total number initialization
static unsigned int Totalline;
static unsigned int Totallexeme;
static unsigned int Totalword;



#define NextChar() ((*forward)? *forward++:((forward=buf+BufSize+1),fillbuf(fp)))

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


  register unsigned int Newline_count = 0;
  register unsigned int Space_count = 0;
  register unsigned int Word_count = 0;
  register unsigned char ch;  


  buf[BufSize*2] = Sentinel;
  forward = buf + BufSize*2;
  lexeme_beginning = forward;

  fp = fopen(fname, "r");

  while(ch = NextChar())
  {
    fprintf(stdout, "Next : %c\n", ch);

    if(ch==10)(Newline_count++);
    //fprintf(stdout, "newline : %d  ",Newline_count);
    if(ch==32||ch==9 || ch==0)(Space_count++);
    //fprintf(stdout, "space: %d  ", Space_count);
    Word_count++;
    //fprintf(stdout, "Total : %d\n", Word_count);
  }
	Totalline += Newline_count;
	Totallexeme += (Newline_count + Space_count);
	Totalword += Word_count;
  //fprintf(stdout, "while : \n %d %d %d", Totalline, Totallexeme, Totalword);
}

void printtotal()
{
/* FILL IN THIS BLANK */
  fprintf(stdout, "\n %d %d %d", Totalline, Totallexeme, Totalword);
}
