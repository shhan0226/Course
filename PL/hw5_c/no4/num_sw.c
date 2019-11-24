#include <stdio.h>
#define MAX 1000

int main(int argc, char *argv[])
{


  
  int number, i, count = 1;
  int x = 0;
  int y = 0;


  printf("input number: ");
  scanf("%d", &number);

  if(number == 1)
  {
    printf("0,0");
  }
  else if( (number == 0) || (number == MAX))
  {
    printf("error");
  } 
  else
  { 
    for(i=1; i<number; i++)
    {
       if(count == 7)
       { 
         count =1;
       }
       switch(count)
       {
         case 1:
                 y++;
                 count++;
                 break;
         case 2:
                 x--;
                 count++;
                 break;
         case 3:
                 y--;
                 count++;
                 break;
         case 4:
                 x++;
                 y--;
                 count++;
                 break;
         case 5:
                 x++;
                 count++;
                 break;
         case 6:
                 y++;
                 count++;
                 break;
       }
       
    
    }

    printf("%d,%d",x,y);
  }

}
