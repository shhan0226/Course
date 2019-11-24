#include "omp.h"

int printf(char *, ...);


main()
{
   int i, myproc;
   
   #pragma omp parallel private(myproc,i)
   {
      myproc = omp_get_thread_num();
      printf("--%d\n", myproc);
      #pragma omp for
      for(i=0; i<9; i++)
      {
         printf("%d %d\n", myproc, i);
      }

   }
}
