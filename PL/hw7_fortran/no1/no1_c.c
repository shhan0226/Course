#include "stdio.h"
#include "memory.h"
#include "string.h"
#include "stdlib.h"

char *replace_(char *s){

  char *result, *str;          //declaration char pointer
  int count, len, start, i, j; //declaration int 
  count = 0;                   //initialization counter
  start = 0;                   //initialization start
  len = strlen(s);             //initialization string length  

  result = (char *) malloc(len);  //result string dynamic allocation

  str = result;                   //str pointer allocation  
  for(i =0; s[i] != '\0'; i++){   //loop until end of stirng
    if(s[i] != s[i+1]){           //number of ith and nubmer of i+1th are different
  
     if(count < 2){               //when counter less than 2
      for(j = start; j <= i; j++){//assignment j to start location , until i ) 
          *str = s[j];               //input string from s
          str++;                    //stirng pointer +1
        }
        start = i+1;                //reallocation start location 
        count = 0;                  //initialization counter
      }
     else{                        //when counter grater tane 2
       *str = 48;                  //input '0' to stirng
       str++;                      //string pointer +1
       count = 0;                  //initialization counter
       start = i+1;                //reallocatin start location
      }
    }

   else{                        //character of ith and cahracter of i+1th are the same
     count++;
    }
 }

  *str = '\0';                  //input '\0' to string
  return result;
}

void rep_(char *s){

  char *s2;
  int s_len;
  s_len = strlen(s);

  while(s_len){
     s2 = replace_(s);
     strcpy(s, s2);
     s_len--;
  }

  printf("result : %s\n",s2);


}

