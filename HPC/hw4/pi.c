#include <omp.h>
#include <math.h>

# define N 200000000


main()
{
  int start, end;
  double area =0, dx=0;
  long i;
  dx= 1.0/N;
  
  start = millisecond();

  #pragma omp parallel for private(i) reduction(+:area)
  {
    for(i=0; i<=N; i++)
    {
     area += sqrt(1 - ( ((double)i*dx)*((double)i*dx) ) ) * dx;
    }
  }

  end = millisecond();

  printf("time: %d, area: %f\n", end-start, area);
  printf("pi: %30.25f\n", area*4.0);

  exit(0);


}
