vecadd: vecadd.o millisecond.o
	mpicc -o vecadd vecadd.o -lm -ltime -L.

vecadd.o: vecadd.c
	mpicc -c vecadd.c

millisecond.o: millisecond.c
	cc -c millisecond.c
	ar -cr libtime.a millisecond.o
	ranlib libtime.a

clean:
	rm *.o

run:
	mpiexec -machinefile machines -n 8 pi
