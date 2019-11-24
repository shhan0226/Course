#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 1024
int main(int argc, char* argv)
{

  int i, j, k, l , m, n;
  char str[MAX], newstr[MAX], sw[MAX], in[MAX];
  char *pstr, *pnewstr, *psw, *pin, start, end;
  
  int count =1;
  int len;

  printf("original str: ");
  scanf("%s",&str);
  printf("%s\n", str);
  
  printf("swap str: ");
  scanf("%d",&sw);
  printf("%s\n", sw);

  /*
  printf("new str: ");
  scanf("%s",&in);
  len = strlen(in);
  */

  memset(str, 0, sizeof(str));
  memset(newstr, 0, sizeof(newstr));
  memset(sw, 0, sizeof(sw));
  memset(in, 0, sizeof(in));


  pstr = str;
  pnewstr = newstr;
  psw = sw;
  pin = in;

  

/*
  while(pstr == 0)
  {
   if(psw ==0)
   { 
     for(i=0; i< len ;i++){
       newpstr = in[i];
       newpstr++;
     }
   }
   
   if(psw == pstr++)
   {
     psw++;
   }
   else
   {
     psw = sw;
     newpstr = (pstr-1);
     newpstr++;
     
   }
   
  
  }
  */


  return 0;


}
