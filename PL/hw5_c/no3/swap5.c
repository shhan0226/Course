#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceAll(char *s, const char *olds, const char *news);
int recall(char *s, char* pa);

int main(){
  char s[] = "000000000000000000";
  char *s2, *s3;
  char pa[4];
  int num;

  //printf("init: %s\n", s);

      printf("input : ");
      scanf("%s",&s);
            
      s2 = replaceAll(s, "111", "0");
      strcpy(s, s2);
      s2 = replaceAll(s, "000", "0");
      strcpy(s, s2);

      //printf("--%d\n", recall(s,pa));

     while( (0 != recall(s,"111") ) || ( 0 != recall(s,"000") ) )
      {
      s2 = replaceAll(s, "111", "0");
      strcpy(s, s2);
      s2 = replaceAll(s, "000", "0");
      strcpy(s, s2);
      }
  //    printf("%s\n",s);
  
  
  // 에러가 있으면 NULL 을 리턴. 에러가 없으면 결과 출력
  (s2 != NULL) ? printf("치환: %s\n", s2) : fputs("Replace String Error...\n", stderr);
}


int recall(char *s, char *pa){
  
  int strsize = strlen(s);
  int swsize = strlen(pa);
  int i, j;
  
  for(i=0; i <=(strsize - swsize); i++)
  {
    for(j=0; j<swsize; j++)
    {
      if(s[i+j] != pa[j])
      {
         break;
      }
    }
    if(j >= swsize)
    {
          return i+1;
    }
  }

  return 0;
}


char *replaceAll(char *s, const char *olds, const char *news) {
  char *result, *sr;
  size_t i, count = 0;
  size_t oldlen = strlen(olds); if (oldlen < 1) return s;
  size_t newlen = strlen(news);


  if (newlen != oldlen) {
    for (i = 0; s[i] != '\0';) {
      if (memcmp(&s[i], olds, oldlen) == 0) count++, i += oldlen;
      else i++;
    }
  } else i = strlen(s);


  result = (char *) malloc(i + 1 + count * (newlen - oldlen));
  if (result == NULL) return NULL;


  sr = result;
  while (*s) {
    if (memcmp(s, olds, oldlen) == 0) {
      memcpy(sr, news, newlen);
      sr += newlen;
      s  += oldlen;
    } else *sr++ = *s++;
  }
  *sr = '\0';

  return sr;
}
