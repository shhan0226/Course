#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <fstream>

#define MAX 1024

using namespace std;

class Replace
{

  public:
    char *result, *str, *s, *olds, *news;             // vairable declare
    int i, count, oldlen, newlen;
    char* putString();                          
    void getString(char *s, char *olds, char *news);  // funtion declare
  
};

void  Replace::getString(char *s, char *olds, char*news)
{                                                     // mem-funtion intiialization
  this->s = s;
  this->olds = olds;
  this->news = news;
  count =0;
  oldlen = strlen(olds);
  newlen = strlen(news);

}

char* Replace::putString()
{
  if (oldlen < 1) return s;                           //if olds not be return stirng 

  if (newlen != oldlen) {                             //if olds and news not equal 
    for (i = 0; s[i] != '\0';) {                  
      if (memcmp(&s[i], olds, oldlen) == 0){          //if find old word
          count++;                                    //number of string  counter +1
          i += oldlen;
      }
      else i++;
    }
  } else i = strlen(s);                               //if olds and news equal 
                                                      //string dynamic allocation
  result = new char[i + 1 + count * (newlen - oldlen)]; 
  if (result == NULL) return NULL;                             

  str = result;                                       //str pointer result stirng

  while (*s) {                                        //until input stirng find EOF
    if (memcmp(s, olds, oldlen) == 0) {               //find old word in stirng then
      memcpy(str, news, newlen);                      //copy new word to stirng
      str += newlen;                                  //stirng length increase
      s  += oldlen;
    } else *str++ = *s++;
  }
  *str = '\0';                                        //end input '\0'

  return result;
}

int main(int argc, char* argv){

  FILE *fp_r = NULL;                                  //file pointer initialization
  FILE *fp_w = NULL;
  FILE *fp_p = NULL;

  Replace rep;
  
  char data_Buffer[MAX];                              //buffer declaration
  char replace_Buffer[MAX];
  
  char string[MAX];                                   //stirng declaration
  char *pt_d,*pt_r, *str, *s, *sp;                    //character pointer

  char f_str[MAX],r_str[MAX];
  char in_file[MAX], out_file[MAX], re_file[MAX];
 
  cout << "input file : ";                            //input in file name
  cin >> in_file;
  cout <<"replace file : ";                           //input replace file name
  cin >> re_file;
  cout <<"output file : ";                            //input outfile name
  cin >> out_file;
  
  fp_r = fopen(in_file, "r");                         //file open
  fp_w = fopen(out_file, "w");

  
  if( fp_r == NULL) return 0;

  pt_d = data_Buffer;                                 //pointer allocation
  pt_r = replace_Buffer;
  sp =string;

  while(fgets(pt_d, sizeof(data_Buffer), fp_r)){      //read in file

    fp_p = fopen(re_file, "r");
    if(fp_p == NULL) return 0;
  
    strcpy(string, pt_d);
    cout << endl <<"in stirng : ";
    
    while(fgets(pt_r, sizeof(replace_Buffer),fp_p)){  //read replace file
   
      str = strtok(pt_r , ",");                       //token old word
      strcpy(f_str, str);         
      while(str = strtok(NULL, "\n")){                //token new word
          strcpy(r_str, str);
       }
    
      cout << "find : |" << f_str;
      cout << "replace : => " << r_str;
    
      rep.getString(string, f_str, r_str);
      s = rep.putString();
      cout <<"out string : " << s ;
      strcpy(sp ,s);

      }

    fputs(sp, fp_w);                                 //output file
    fclose(fp_p);                                    //file close

  }

  fclose(fp_w);
  fclose(fp_r);

  return 0;
}
