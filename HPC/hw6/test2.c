#include "mpi.h"
#include <stdio.h>
#include <string.h>



main(int argc, char *argv[])
{
  int nproc, my_proc;
  char msg[100];
  int i, tag;
  MPI_Status status;


  MPI_Init(&argc, &argv);


  MPI_Comm_size(MPI_COMM_WORLD, &nproc);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_proc);
  printf("%d %d\n", nproc, my_proc);



  if(my_proc == 0)
  {
    for(i=1; i<nproc ; i++)
    {
      MPI_Recv(msg, 100, MPI_CHAR, i, tag, MPI_COMM_WORLD, &status );
      printf("%s\n", msg);
    }
  }

  else  
  {
    sprintf(msg, "Hello World from %d", my_proc);
    MPI_Send(msg, strlen(msg)+1, MPI_CHAR, 0, tag, MPI_COMM_WORLD );
  }
   

  MPI_Finalize();

}
