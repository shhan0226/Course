#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 1024


char *replace(char *s, const char *olds, const char *news) 
{
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
  while (*s !='\0' ) {
    if (memcmp(s, olds, oldlen) == 0) {
      memcpy(st, news, newlen);
      st += newlen;
      s  += oldlen;
    } else *st++ = *s++;
  }
  *st = '\0';

  return result;
}


char *tran(char *s)
{
  char *result;
  //printf("%s\n",s); 
  result = replace(s, "원", "1");
 // printf("%s\n",result);
  result = replace(result, "일", "1*");
  //printf("%s\n",result);
  result = replace(result, "이", "2*");
  //printf("%s\n",result);
  result = replace(result, "삼", "3*");
  //printf("%s\n",result);
  result = replace(result, "사", "4*");
  //printf("%s\n",result);
  result = replace(result, "오", "5*");
  //printf("%s\n",result);
  result = replace(result, "육", "6*");
  //printf("%s\n",result);
  result = replace(result, "칠", "7*");
 // printf("%s\n",result);
  result = replace(result, "팔", "8*");
  //printf("%s\n",result);
  result = replace(result, "구", "9*");
  //printf("%s\n",result);
  result = replace(result, "십", "10*");
  //printf("%s\n",result);
  result = replace(result, "백", "100*");
  //printf("%s\n",result);
  result = replace(result, "천", "1000*");
  //printf("%s\n",result);
  result = replace(result, "만", "10000*");
  //printf("%s\n",result);
  result = replace(result, "억", "1000000000*");
  //printf("%s\n",result);
  result = replace(result, " ", "");
  return result;
} 




int main(int argc, char* argv){



  FILE *fp = NULL;
  char Buffer[MAX];
  char in_file[MAX];
  char *s, *pt;
  
  
  if(fp =NULL)return;
  pt = Buffer;

  printf("input file : ");
  scanf("%s", &in_file);
  
  fp = fopen(in_file, "r");
  while(fgets(Buffer, sizeof(Buffer), fp)){

    printf("text : %s",pt);
    s = tran(pt);
    printf("%s",s);


  }

  fclose(fp);
  return 0;
}
