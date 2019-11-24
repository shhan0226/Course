#include <stdio.h>
#define N 400
#define THREADS 16
#define A(i, j) A[i*N+j]
#define B(i, j) B[i*N+j]
#define C(i, j) C[i*N+j]

__global__ void matAdd(float *A, float *B, float *C)
{
  unsigned int i = blockIdx.x*blockDim.x+threadIdx.x;
  unsigned int j = blockIdx.y*blockDim.y+threadIdx.y;

  C(i,j) = A(i,j) + B(i,j);
}

int main()
{

  float A[N][N], B[N][N], C[N][N], C2[N][N];
  float *A_d, *B_d, *C_d;
  int i, j;
  
  dim3 dimBlock(THREADS, THREADS);
  dim3 dimGrid((N+dimBlock.x-1)/dimBlock.x,((N+dimBlock.y-1)/dimBlock.y));

  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      A[i][j] = i*j;
      B[i][j] = i+j;
      C2[i][j] = A[i][j] + B[i][j];
    }
  }  
  
  /*Allocate array on device*/
  cudaMalloc((void**) &A_d, sizeof(float)*N*N);
  cudaMalloc((void**) &B_d, sizeof(float)*N*N);
  cudaMalloc((void**) &C_d, sizeof(float)*N*N);

  /*Copy array from host memory to device memory*/
  cudaMemcpy(A_d, A, sizeof(float)*N*N, cudaMemcpyHostToDevice);
  cudaMemcpy(B_d, B, sizeof(float)*N*N, cudaMemcpyHostToDevice);

  matAdd<<<dimGrid, dimBlock>>>(A_d, B_d, C_d);

  /*Copy the result back*/
  cudaMemcpy(C, C_d, sizeof(float)*N*N, cudaMemcpyDeviceToHost);

  for( i=0; i<N; i++)
    for(j=0; j<N; j++)
      if(C[i][j] != C2[i][j]) printf("%d %f %f\n", i, C[i][j], C2[i][j]);

   printf("OK!!\n");

  /*Free memory on the device */
  cudaFree(A_d);
  cudaFree(B_d);
  cudaFree(C_d);

}
