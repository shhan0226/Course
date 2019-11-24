#include <stdio.h>

#define N 160
#define THREADS 16


__global__ void reduce_kernel(float *A, float *cols)
{
  extern __shared__ float sdata[];
  sdata[threadIdx.x] = A[threadIdx.x];

  // do reduce in shared memory
  for(unsigned int s = blockDim.x/2; s>0; s>>=1)
  {
    if(threadIdx.x <s) sdata[threadIdx.x] += sdata[threadIdx.x+s];
    __syncthreads();
  }

  // write resul for this block to global memory
  if(threadIdx.x ==0) *cols = sdata[0];
}



int main(){


  float A[N], *cols, sum;
  float *cols_d, *A_d;
  int i;

  dim3 dimBlock(THREADS);
  dim3 dimGrid((N+dimBlock.x-1)/dimBlock.x );



  for(i=0; i<N; i++){
    A[i] = i+1;  //1~160 claculation i+1
  }
  
  int sdata = THREADS * sizeof(float);
  cols = (float*)malloc(sizeof(float)*dimGrid.x);
  //cols = (float*)malloc(sizeof(float));

  cudaMalloc( (void **) &cols_d, sizeof(float)*dimGrid.x );
  cudaMalloc( (void **) &A_d, sizeof(float)*N );

  cudaMemcpy(A_d, A, sizeof(float)*N, cudaMemcpyHostToDevice);
  reduce_kernel<<<dimGrid, dimBlock, sdata>>>(A_d, cols_d);

  //copy values from Gpu memory to Cpu memory
  cudaMemcpy(cols, cols_d, sizeof(float)*dimGrid.x, cudaMemcpyDeviceToHost);

  //add the computed value to the value of pi
  // sum = *cols;

  sum = 0.0;
  for(i=0; i<dimGrid.x; i++)
   sum +=cols[i];
 
  printf("%f\n",sum);
  
  cudaFree(A_d);
  cudaFree(cols_d);


}


