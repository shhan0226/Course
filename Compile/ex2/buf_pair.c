#include <stdio.h>
#include <stdlib.h>

#define BufSize 8
#define Sentinel '\0'

static unsigned char buf[BufSize*2+1];
static unsigned char *lexeme_beginning, *forward;

#define NextChar() ((*forward)? *forward++:((forward=buf+BufSize+1),fillbuf(fp)))
static unsigned char fillbuf(FILE *fp)
{
  register unsigned char *i, *j;
  
  /* move the rest of token to the other buffer*/
  i = lexeme_beginning;
  j = lexeme_beginning - BufSize;

  while (j < (forward-1)){
     *(j++) = *(i++); 
  }

  lexeme_beginning -= BufSize;
  buf[BufSize + fread(buf+BufSize, 1, BufSize, fp)] = Sentinel;
  return buf[BufSize];
	
}

void prtBuffer()
{
  int i;
  fprintf(stdout, "Buffer:  ");
  for ( i = 0; i < 2*BufSize+1; i++){
    if (i%BufSize==0) fprintf(stdout, "|");
    if ((buf[i]==0)||(buf[i]==10)||(buf[i]==32)) printf(".");
    else fprintf(stdout, "%c", buf[i]);
  }
  fprintf(stdout, "|\n");

}


int main(int argc, char *argv[])
{
  register FILE *fp;
  register unsigned char ch;
  int i;

  if (argc != 2){
    fprintf(stderr, "input error\n");
    exit(1);
  }

  buf[BufSize*2] = Sentinel;
  forward = buf + BufSize*2;
  lexeme_beginning = forward;

  fp = fopen(argv[1], "r");

  while (ch = NextChar()){
    prtBuffer();
    fprintf(stdout, "Next char: %c(%d) \n\n", ch, ch);
    lexeme_beginning = buf + BufSize;
  }

  fclose(fp);
  exit(0);

}
