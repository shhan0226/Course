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
  int i, j, k, l , m, n;
  char str[6][4] ;
  char buf[4];
  char string[18];
  int count =1;

  for(i=0; i<6; i++)
  {
    printf("input string no.%d :\n", i);
    scanf("%s",&buf[0]);
    //gets(pt);
    str[i][0] = buf[0];
    str[i][1] = buf[1];
    str[i][2] = buf[2];
    //printf(" %c%c%c\n", str[i][0], str[i][1], str[i][2]);
  }

  printf("--OK! Let's go---------\n");

  for(i=0; i<6; i++){
    for(j=0; j<6; j++){
      if(i != j)
      {
        for(k=0; k<6; k++){
         if( (k !=j) && (k !=i) )
         {
           for(l=0; l<6; l++){
             if( (l !=k) && (l !=j) && (l != i))
             {
               for(m=0; m<6; m++){
                 if( (m !=l) && (m != k) && (m !=j) && (m !=i))
                 {
                   for(n=0; n<6; n++)
                   if( (n != m) && (n != l) && (n != k) && (n !=j) &&(n !=i) ){

                       string[0]= str[i][0];

                       string[1] = str[i][1];
                       string[2]= str[i][2];
                       string[3] = str[j][0];
                       string[4]= str[j][1];
                       string[5] = str[j][2];
                       string[6] = str[k][0];
                       string[7] = str[k][1];
                       string[8] = str[k][2];
                       string[9] = str[l][0];
                       string[10] = str[l][1];
                       string[11] = str[l][2];
                       string[12] = str[m][0];
                       string[13] = str[m][1];
                       string[14] = str[m][2];
                       string[15] = str[n][0];
                       string[16] = str[n][1];
                       string[17] = str[n][2];

                       printf("%d :%s => " ,count, string);
                       count++;
                       strcpy(s, string);
                       s2 = replaceAll(s, "111", "0");
                       strcpy(s, s2);
                       s2 = replaceAll(s, "000", "0");
                       strcpy(s, s2);

                       while( (0 != recall(s,"111") ) || ( 0 != recall(s,"000") ) )
                       {
                         s2 = replaceAll(s, "111", "0");
                         strcpy(s, s2);
                         s2 = replaceAll(s, "000", "0");
                         strcpy(s, s2);
                       }
    
                       (s2 != NULL) ? printf("result: %s\n", s2) : fputs("Replace String Error...\n", stderr);

                   }
                 }
               }
             }
           }
         }
       }
      }
    }
  }






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
  unsigned int i, count = 0;
  unsigned int oldlen = strlen(olds); if (oldlen < 1) return s;
  unsigned int  newlen = strlen(news);


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

  return result;
}
