#include "omp.h"

int printf(char *, ...);


main()
{
   int i, myproc;
   
   #pragma omp parallel for private(myproc,i)
   {
      for(i=0; i<9; i++)
      {
         myproc = omp_get_thread_num();
         printf("%d %d\n", myproc, i);
      }

   }
}
