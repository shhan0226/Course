#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char *replace(char *s){

  char *result, *str;
  int count, len, start, i, j;
  count = 0;
  start =0;
  len = strlen(s);
  
  result = (char *) malloc(len);
  
  str = result;
  for(i =0; s[i] != '\0'; i++)
  {
    if(s[i] != s[i+1]){
     if(count < 2) {
      for(j =start; j <=i; j++){
       *str = s[j];
        str++;
      }
      start = i+1;
      count = 0;
     }
     else{
      *str = 48;
      str++;
      count = 0;
      start = i+1;
     }
    }
    else
    {
     count++;
    }
  }
  
  *str = '\0';

  return result;
}


int main(int argc, char * argv)
{

 char s[] ="110i101000110000";
 char *s2, *s3;
 
 printf("old : %s => ",s);
 s2 = replace(s);
 
  printf("result : %s\n", s2);




  return 0;
}

