#define N 500000000

main()
{
   float *A, *B, X, Y;
   long i, j;
   int start, stop, mflops;

   /*generate the input vector*/
   A = malloc(sizeof(float)*N);
   B = malloc(sizeof(float)*N);
   
   for(i=0; i<N; i++)
   {
      A[i] = i;
   }
   
   X= 1.23;
   Y= 2.34;
  
   start = millisecond();

   #pragma omp parallel for shared(A, B, X, Y, i)
   {
      for(i=0; i<N; i++)
      {
         B[i]= A[i]*X +Y;
      }
   }
   stop = millisecond();
  
   printf("milli? %d\n", stop-start);
   mflops = (2*N)/(((float)(stop-start)*1000));
   printf("MFLOPS? %d",mflops); 
   
   free(A);
   free(B);
  
   exit(0);
}
   
