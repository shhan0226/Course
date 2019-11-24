#include <stdio.h>
int func(void)
{
 //static int count=0;
 int count=0;
  count++;
  return count;
}

int main(void)
{
  int i;
  for(i=0; i<10; i++)
    printf("%d",func());
  return 0;
}
