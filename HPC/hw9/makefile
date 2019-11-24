pi: pi.o millisecond.o
	nvcc -o pi pi.o millisecond.o -lm

pi.o: pi.cu
	nvcc -c pi.cu

millisecond.o: millisecond.cu
	nvcc -c millisecond.cu

clean:
	rm *.o

run:
	mpiexec -machinefile machines -n 8 pi
