#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 1024


char *replace(char *s, const char *olds, const char *news) {
  char *result, *st;
  unsigned int i, count = 0;
  unsigned int oldlen = strlen(olds); 
  unsigned int  newlen = strlen(news);

 
  if (oldlen < 1) return s;

  if (newlen != oldlen) {
    for (i = 0; s[i] != '\0';) {
      if (memcmp(&s[i], olds, oldlen) == 0){
          count++;
          i += oldlen;
      }
      else i++;
    }
  } else i = strlen(s);


  result = (char *) malloc(i + 1 + count * (newlen - oldlen));
  if (result == NULL) return NULL;


  st = result;
  while (*s) {
    if (memcmp(s, olds, oldlen) == 0) {
      memcpy(st, news, newlen);
      st += newlen;
      s  += oldlen;
    } else *st++ = *s++;
  }
  *st = '\0';

  return result;
}





int main(int argc, char* argv){



  FILE *fp = NULL;
  FILE *fp2 = NULL;
  
  char Buffer[MAX];
  char string[MAX];
  char *pt, *str, *s;

  char f_str[MAX],r_str[MAX];
  char in_file[MAX], out_file[MAX];

  printf("input file : ");
  scanf("%s", &in_file);
  printf("output file : ");
  scanf("%s", &out_file);

  

  fp = fopen(in_file, "r");
  fp2 = fopen(out_file, "w");

  if(fp == NULL) return;
  pt = Buffer;


  printf("find string : ");
  scanf("%s", &f_str);
  printf("=>%s\n", f_str);  

  printf("replace string : ");
  scanf("%s", &r_str);
  printf("=>%s\n", r_str);  
 

  while(fgets(Buffer, sizeof(Buffer), fp)){

    strcpy(string, pt);
    s = replace(string, f_str, r_str);
    fputs(s, fp2);  
  

  }

  fclose(fp);
  fclose(fp2);




  return 0;
}
