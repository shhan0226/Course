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
/*

#define IN 1
#define OUT 0
#define IsWhite(c) (whitechars[c])

static int whitechars[256] ={
 0, 0, 0, 0, 0, 0 ,0, 0, ,....
}
#define IsWhite(c) (whitechars[c])
*/

#define OUT 0
#define OUT 1 


void countfile(FILE *fp, char *fname)
{
/* FILL IN THIS BLANK */
/*
	
  //buffer initialization
  buf[BufSize*2] = Sentinel;
  forward = buf + BufSize*2;
  lexeme_beginning = forward;
  
  register int nl, nw, nc;
  register int state;
  register unsigned char ch;

  nl = nw = nc =0;
  state = OUT

  while(ch = NextCahr(0))
  {
    ++nc;
    if(ch =='\n') ++nl;
    if (IsWhite(ch))
    {
      lexeme_beginning = forword;
      state = OUT;
    }
    else if(state == OUT)
    {
       state = IN;
       ++nw;
    }
  }
  printf("%d %d %d %s\n", nl, nw, nc, fname);
  tn1 += nl;
  tnw +=nw;
  tnc += nc;

*/
  //word counter variable initialization
  register unsigned int Newline_count = 0;
  register unsigned int Space_count = 0;
  register unsigned int Word_count = 0;
  register unsigned char ch;  

  //buffer initialization
  buf[BufSize*2] = Sentinel;
  forward = buf + BufSize*2;
  lexeme_beginning = forward;

  //file open and read
  fp = fopen(fname, "r");

  //one buffer char read
  while(ch = NextChar())
  {
    //new lien counter
    if(ch==10)(Newline_count++);
    //new space counter
    if(ch==32||ch==9 || ch==0)(Space_count++);
    //new word counter
    Word_count++;
  }

  fprintf(stdout, "file[%s]	%d %d %d\n",fname,Newline_count,Newline_count+Space_count, Word_count);
        //total number calculater
	Totalline += Newline_count;
	Totallexeme += (Newline_count + Space_count);
	Totalword += Word_count;
}

void printtotal()
{
/* FILL IN THIS BLANK */
  fprintf(stdout, "totlal	%d %d %d\n", Totalline, Totallexeme, Totalword);
}
