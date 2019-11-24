#include <omp.h>

int printf(char *, ...);


int main()
{
   int my_proc;
   int sum = 0;

   int s = 1;
   #pragma omp parallel private(my_proc) shared(sum, s)
   {
      while(!s);
      s = 0;
      printf("---%d\n", omp_get_num_threads());
      my_proc = omp_get_thread_num();
      printf("%d\n", my_proc);
      sum += my_proc;
      s =1;
   }

   printf("%d\n", sum);
}
