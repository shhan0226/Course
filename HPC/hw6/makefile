pi: pi.o millisecond.o
	mpicc -o pi pi.o -lm -ltime -L.

pi.o: pi.c
	mpicc -c pi.c

millisecond.o: millisecond.c
	cc -c millisecond.c
	ar -cr libtime.a millisecond.o
	ranlib libtime.a

clean:
	rm *.o

run:
	mpiexec -machinefile machines -n 8 pi
