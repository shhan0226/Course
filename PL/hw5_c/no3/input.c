#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 1024


int main(int argc, char* argv){



  FILE *fp = NULL;
  FILE *fp2 = NULL;
  
  char Buffer[MAX];
  char *pt, *str;

  fp = fopen("text", "r");
  fp2 = fopen("text2", "w");

  if(fp == NULL) return;
  pt = Buffer;

  while(fgets(Buffer, sizeof(Buffer), fp)){

    
    printf("%s",Buffer); 
    fputs(Buffer, fp2);  
  

  }







  return 0;
}
