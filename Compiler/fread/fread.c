#include <string.h>
#include <stdio.h>

#define BufSize 8
int main(void)
{
  FILE *fp;
  char msg[100];
  fp = fopen("text","r");

  printf("%d\n",fread(msg, 1, BufSize, fp)); 
  printf("%s\n", msg );
  printf("%d\n", msg[7] );
  printf("%d\n",fread(msg, 1, BufSize, fp)); 
  printf("%s\n", msg );
  printf("%d\n",fread(msg, 1, BufSize, fp)); 
  printf("%s\n", msg );

  int i;
 int j;
  for(i = 0 ; i< 2*BufSize+1; i++){
   printf("[%d " ,i);
   j= i % BufSize;
   printf ("%d]\n", j); 
  }

  char *str1, *str2;

  str1 = msg;
  str2 = str1;

  str1++;

   printf ("str1 %s\n", str1); 

   printf ("str2 %s\n", str2); 

   printf ("new %c", 10); 
   printf ("null %c\n", 0); 
}
