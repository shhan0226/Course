#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 1024
int main(int argc, char* argv)
{

  int i, j, k, l , m, n;
  char str[MAX], sw[MAX];
  char *pstr, *pnewstr, *psw, *pin, start, end;
  
  int count =1;
  int len;
  int strsize, swsize;



  printf("original str: ");
  scanf("%s",&str);
  //printf("%s\n", str);
  strsize = strlen(str);
  printf("%d\n", strsize);
 

 
  printf("swap str: ");
  scanf("%s",&sw);
  //printf("%s\n", sw);
  swsize = strlen(sw);
  printf("%d\n", swsize);



  for(i=0; i <=(strsize - swsize); i++)
  {
    for(j=0; j<swsize; j++)
    {
      if(str[i+j] != sw[j])
      {
         break;
      }
    }
    if(j >= swsize)
    {
          printf("%d\n", i);
    }
  }

  return 0;


}
