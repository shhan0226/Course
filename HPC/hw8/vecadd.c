#include "mpi.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1600000


main(int argc, char *argv[])
{
  float *A, *B, *C;
  float *local_A, *local_B, *local_C;
  long i, j;
  int nproc, my_proc;

  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_proc);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);



  /*generate the input vectors*/
  if(my_proc == 0){
  A = malloc(sizeof(float)*N);
  B = malloc(sizeof(float)*N);
  for(i=0; i<N; i++){
    A[i] = rand();
    B[i] = rand();
    }
  }
  local_A = malloc(sizeof(float)*N/nproc);
  local_B = malloc(sizeof(float)*N/nproc);

  MPI_Scatter(A, N/nproc, MPI_FLOAT, local_A, N/nproc, MPI_FLOAT,0,MPI_COMM_WORLD);
  MPI_Scatter(B, N/nproc, MPI_FLOAT, local_B, N/nproc, MPI_FLOAT,0,MPI_COMM_WORLD);
  
  for(i=0; i<N/nproc; i++){
    local_A[i] = local_A[i]+local_B[j];
  }
  /*generate the output vectors*/
  if(my_proc ==0){
  C = malloc(sizeof(float)*N);
  }
  MPI_Gather(local_A, N/nproc, MPI_FLOAT, C, N/nproc, MPI_FLOAT, 0, MPI_COMM_WORLD);
  

  /*check the results*/
  if(my_proc==0){
  for(i=0; i<N; i++)
    if((A[i]+B[j]) != C[i]) printf("%d\n", i);
    printf("ok!!");
  }
  free(A);
  free(B);
  free(C);
  exit(0);
  MPI_Finalize();
 
}
