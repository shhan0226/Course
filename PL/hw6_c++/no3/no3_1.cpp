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
    char *result, *str, *s, *olds, *news;                             // character pointer
    int i, count;                               // vairable initialization     
    int oldlen;                      // find string length initialization
    int  newlen;
    char* putString();
    void getString(char *s, char *olds, char *news);
  
};

void  Replace::getString(char *s, char *olds, char*news)
{
  this->s = s;
  this->olds = olds;
  this->news = news;
  count =0;
  oldlen = strlen(olds);
  newlen = strlen(news);

}

char* Replace::putString()
{
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
  result = new char[i + 1 + count * (newlen - oldlen)]; 
  //if (result == NULL) return NULL;                             

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



int main(void){

  Replace rep;
  
  char data_Buffer[MAX];                    //buffer declaration
  char replace_Buffer[MAX];
  
  char string[MAX];                         //stirng declaration
  char *pt_d,*pt_r, *str, *s, *sp;          //character pointer

  char f_str[MAX],r_str[MAX];
  char in_file[MAX], out_file[MAX], re_file[MAX];
 
  printf("input file : ");                  //input in file name
  cin >> in_file;
  printf("replace file : ");                //input replace file name
  cin >> re_file;
  printf("output file : ");                 //input outfile name
  cin >> out_file;

  
  
  ofstream outfile;
  outfile.open(out_file);
  
  ifstream infile(in_file);
  if(!infile){
    cout<<"do not file";
    return 0;
  }

  pt_d = data_Buffer;                       //pointer allocation
  pt_r = replace_Buffer;
  sp = string;

  while( !infile.eof() )
  {                                                   //read in file
    infile.getline(pt_d, sizeof(data_Buffer));
    cout << pt_d << endl;

    strcpy(string, pt_d);
    
    ifstream infile2(re_file);
    if(!infile2){
      cout<<"do not file2";
      return 0;
    }


    while( !infile2.eof() )
    { 
      infile2.getline(pt_r, sizeof(replace_Buffer));

      str = strtok(pt_r , ",");                      //token old word
      strcpy(f_str, str);
      cout << "find : " << f_str;

      str = strtok(NULL, "\n");                      //token new word
      strcpy(r_str, str);
      cout << "=> replace : " << r_str << endl;
      
    
      rep.getString(string, f_str, r_str);
      s = rep.putString();

      cout << "out string : " << s<< endl;
      strcpy(sp , s);
      cout <<"ok1"<<endl;

    }
    
    infile2.close();
    //outfile << sp << endl;

  }

  outfile.close();
  infile.close();


  return 0;
}
