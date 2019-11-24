#include <stdio.h>

#define L 40
#define N 25600000
#define THREADS 512

__global__ void pi_kernel(float *cols, float p1, float p2)
{
  unsigned int i = blockIdx.x*blockDim.x+threadIdx.x;
  float xval, height, width;

  extern __shared__ float reduce[];

  // calculate each segement
  /* FILL */
    xval = 0.0;
    width = (p2-p1)/N;
    xval =p1+(width)*i;
    height = sqrt(1.0-xval*xval);
    reduce[threadIdx.x]= width*height;

  __syncthreads();

  // do reduce in shared memory
  /* FILL */
  for(unsigned int s = blockDim.x/2 ; s>0; s>>=1)
  {
    if(threadIdx.x<s)reduce[threadIdx.x] += reduce[threadIdx.x+s];
    __syncthreads();

  }
 
  // write resul for this block to global memory
  /* FILL */
  if(threadIdx.x==0)cols[blockIdx.x] =reduce[0];   

}

extern int millisecond();

int main()
{

  double pi;
  float *cols, *cols_d, p1, p2;
  int start, end;
  int i;
  int j;

  dim3 dimBlock(THREADS);
  dim3 dimGrid( (N+dimBlock.x-1)/dimBlock.x );
  
  int reduce = THREADS * sizeof(float);
  cols = (float*)malloc(sizeof(float)*dimGrid.x);

  start = millisecond();

  cudaMalloc( (void **) &cols_d, sizeof(float)*dimGrid.x );

  p1 = 0.0;
  p2 = 1.0/(float)L;

  pi = 0.0;

  for( i=0; i<L; i++){
    pi_kernel<<<dimGrid, dimBlock, reduce>>>(cols_d, p1, p2);
  
    //copy values from GPU memory to CPU memory
    /* FILL */
    cudaMemcpy(cols, cols_d, sizeof(float)*dimGrid.x, cudaMemcpyDeviceToHost);
   
   //add the computed value to the value of pi
   /*  FILL */  
 
   for(j=0; j<dimGrid.x; j++){
	pi += cols[j];
   }

   p1 =p2;
   p2 = p1 + 1.0/(float)L;

  }
  
  cudaThreadSynchronize();

  end = millisecond();
  
  printf("pi = %17.15f\n", pi*4.0);
  printf("Elapsed time: %d milliseconds\n", end - start);

  cudaFree(cols_d);

}



