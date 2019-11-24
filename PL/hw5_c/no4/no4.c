#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

  char x_val[2];
  char y_val[2];

void num1(int i)
{
  x_val[i+1] = x_val[i] ;
  y_val[i+1] = y_val[i] - 1 ;
}

void num2(int i)
{
  x_val[i+1] = x_val[i] -1;
  y_val[i+1] = y_val[i] -1 ;
}

void num3(int i)
{
  x_val[i+1] = x_val[i] -1 ;
  y_val[i+1] = y_val[i]  ;
}

void num4(int i)
{
  x_val[i+1] = x_val[i] ;
  y_val[i+1] = y_val[i] + 1 ;
}

void num5(int i)
{
  x_val[i+1] = x_val[i] +1;
  y_val[i+1] = y_val[i] +1 ;
}

void num6(int i)
{
  x_val[i+1] = x_val[i] +1;
  y_val[i+1] = y_val[i]  ;
}


int main(int argc, char * argv[])
{


  int i, j;

  x_val[0] = 0;
  y_val[0] = 0;

  num1(0);
  

  

  printf("%d", x_val[1]);
  printf("%d", y_val[1]);
  

  

}
