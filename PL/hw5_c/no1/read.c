#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


int main(int argc, char* argv)
{

  int i, j, k, l , m, n;
  char str[6][4] ;
  char buf[4];
  char string[18];
  char *pt;
  int count =1;


  pt = buf; 
  for(i=0; i<6; i++)
  {
    printf("input string no.%d :\n", i);
    scanf("%s",&buf[0]);
    //gets(pt);
    str[i][0] = buf[0];
    str[i][1] = buf[1];
    str[i][2] = buf[2];
    //printf(" %c%c%c\n", str[i][0], str[i][1], str[i][2]);
    printf("--end---------\n"); 
  }

  printf("--ok---------"); 
  
  pt= string;





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
                       
                       printf("%d :%s\n" ,count, string);
                       count++;
                         
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
  

 

  return 0;


}
