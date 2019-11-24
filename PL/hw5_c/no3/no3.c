#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 1024

char *replace(char *s, char *olds, char *news) {  // stirng replace function 
  char *result, *str;                             // character pointer
  int i, count = 0;                               // vairable initialization     
  int oldlen = strlen(olds);                      // find string length initialization
  int  newlen = strlen(news);
 
  if (oldlen < 1) return s;                     //when old word not be return stirng 

  if (newlen != oldlen) {                  //when old word and new word not equal then
    for (i = 0; s[i] != '\0';) {                  
      if (memcmp(&s[i], olds, oldlen) == 0){    //when find old word
          count++;                              //number of string lncrase counter +1
          i += oldlen;
      }
      else i++;
    }
  } else i = strlen(s);      //when old word and new word equal return nubmer of sting
                             //result string dynamic allocation, number of new stirng
  result = (char *) malloc(i + 1 + count * (newlen - oldlen)); 
  if (result == NULL) return NULL;                             

  str = result;                            //str pointer allocation result stirng

  while (*s) {                             //until input stirng find EOF
    if (memcmp(s, olds, oldlen) == 0) {    //find old word in stirng then
      memcpy(str, news, newlen);           //copy new word to stirng
      str += newlen;                       //stirng length increase
      s  += oldlen;
    } else *str++ = *s++;
  }
  *str = '\0';                              //end input '\0'

  return result;
}

int main(int argc, char* argv){

  FILE *fp_r = NULL;                        //file pointer initialization
  FILE *fp_w = NULL;
  FILE *fp_p = NULL;
  
  char data_Buffer[MAX];                    //buffer declaration
  char replace_Buffer[MAX];
  
  char string[MAX];                         //stirng declaration
  char *pt_d,*pt_r, *str, *s, *sp;          //character pointer

  char f_str[MAX],r_str[MAX];
  char in_file[MAX], out_file[MAX], re_file[MAX];
 
  printf("input file : ");                  //input in file name
  scanf("%s", &in_file);
  printf("replace file : ");                //input replace file name
  scanf("%s", &re_file);
  printf("output file : ");                 //input outfile name
  scanf("%s", &out_file);

  

  fp_r = fopen(in_file, "r");               //file open
  fp_w = fopen(out_file, "w");

  if(fp_r == NULL) return;

  pt_d = data_Buffer;                       //pointer allocation
  pt_r = replace_Buffer;
  sp =string;

  while(fgets(pt_d, sizeof(data_Buffer), fp_r)){    //read in file

    fp_p = fopen(re_file, "r");
    if(fp_p == NULL) return;
  
    strcpy(string, pt_d);
    printf("\nin stirng: %s",string);
    
    while(fgets(pt_r, sizeof(replace_Buffer),fp_p)){ //read replace file
   
      str = strtok(pt_r , ",");                      //token old word
      strcpy(f_str, str);         
      while(str = strtok(NULL, "\n")){               //token new word
          strcpy(r_str, str);
       }
    
      printf("find : %s |", f_str);
      printf("replace : %s => ", r_str);
    
      s = replace(string, f_str, r_str);
      printf("out string :%s", s);
      strcpy(sp ,s);

      }

    fputs(sp, fp_w);                                //output file
    fclose(fp_p);                                   //file close
  

  }

  fclose(fp_w);
  fclose(fp_r);


  return 0;
}
