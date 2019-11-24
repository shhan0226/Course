#include "mpi.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1000000000


main(int argc, char *argv[])
{
  int nproc, my_proc;
  int source, dest;
  int tag =0;	
  long i;
  double width, height, xval, area, total_are;
  int start, end;
  double xm, s_xm, d_xm;
  int or_bit, num;
    

  MPI_Status status;
  
  area =0.0;
  xval =0.0;
  width = (1.0-0.0)/N;
  
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_proc);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);

  /*
  xval = ((float)my_proc*1.0/(float)nproc);
  for(i = 0; i< N/nproc; i++){
  height = sqrt(1.0 -xval *  xval);
  area += width * height;
  xval += width;

  }
  */


  start = millisecond(); 

  
    xm = N/((double)nproc);
    s_xm = xm*((double)my_proc);
    d_xm = xm*((double)my_proc+1);

    for(i=s_xm; i <d_xm ; i++)
    {
       xval = i*width;
       height = sqrt(1.0-xval*xval);
       area += width*height;
    }
  

  //1. MPI_Sen and MPI_Recv
  /*
  if(my_proc == 0)
  {
      total_are=area;
      for(i=1; i<nproc ; i++)
      {
        MPI_Recv(&area, 1, MPI_DOUBLE, i, tag, MPI_COMM_WORLD, &status );
        total_are += (double)area;
      }
  }
  
  else
  {
      MPI_Send(&area, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD );
  }
  */

  //2. MPI_Reduce
  /*
   MPI_Reduce(&area, &total_are, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  */

  //3. Parallel Prefix Sum
  or_bit = nproc;
  total_are = area;
  num = (int)(log(nproc)/log(2));
  for(i =0; i< num; i++){
    if(my_proc < or_bit){
       or_bit = or_bit>>1;
       MPI_Send(&total_are, 1, MPI_DOUBLE, my_proc^or_bit,  tag, MPI_COMM_WORLD);
       MPI_Recv(&area, 1, MPI_DOUBLE, my_proc^or_bit, tag, MPI_COMM_WORLD,&status);
       total_are += area;
     }
  }

 

  end = millisecond();





  if(my_proc ==0)printf("time: %d, area: %30.25f\n", end-start, 4.0*total_are);

  MPI_Finalize();

}
