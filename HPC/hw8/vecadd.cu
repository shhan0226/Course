#define N 10000
#include <stdio.h>

#define THREADS 10


__global__ void vecAdd(float * A, float *B, float *C)
{
  int i = blockDim.x*blockIdx.x+threadIdx.x;
  C[i] = A[i] + B[i];
}

int main()
{
  float A[N], B[N], C[N], C2[N];
  int i;
  float *A_d, *B_d, *C_d;

  dim3 dimBlock(THREADS);


  dim3 dimGrid((N+dimBlock.x-1)/dimBlock.x);

  for(i=0; i<N; i++){
    A[i] = i*2;
    B[i] = N-i;
    C2[i] = A[i] + B[i];
  }
  /*Allocate array on device*/
  cudaMalloc((void**) &A_d, sizeof(float)*N);
  cudaMalloc((void**) &B_d, sizeof(float)*N);
  cudaMalloc((void**) &C_d, sizeof(float)*N);
  
  /*Copy array from host memory to device memory  */
  cudaMemcpy(A_d, A, sizeof(float)*N, cudaMemcpyHostToDevice);
  cudaMemcpy(B_d, B, sizeof(float)*N, cudaMemcpyHostToDevice);

  vecAdd<<<dimGrid, dimBlock>>>(A_d, B_d, C_d);

  /*Copy the result back*/
  cudaMemcpy(C, C_d, sizeof(float)*N, cudaMemcpyDeviceToHost);

  for(i=0; i<N; i++)
    if(C[i] != C2[i]) printf("%d %f %f\n", i, C[i], C2[i]);

  printf("OK!!!\n");
  /*Free meomory on the device*/
  cudaFree(A_d);
  cudaFree(B_d);
  cudaFree(C_d);
}

