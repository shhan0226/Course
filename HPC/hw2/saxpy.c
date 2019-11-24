#define N 500000000

main()
{
   float *A, *B, X, Y;
   long i, j;

   /*generate the input vector*/
   A = malloc(sizeof(float)*N);
   B = malloc(sizeof(float)*N);

   for(i=0; i<N; i++)
   {
      A[i] = i;
   }
   
   X= 1.23;
   Y= 2.34;
   
   for(i=0; i<N; i++)
   {
      B[i]= A[i]*X +Y;
   }
    
   free(A);
   free(B);
  
   exit(0);
}
   
