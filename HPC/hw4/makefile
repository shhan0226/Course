pi: pi.o millisecond.o
	omcc -o pi pi.o -lm -lmillisecond -L.

millisecond.o: millisecond.c
	cc -c millisecond.c
	ar -cr libmillisecond.a millisecond.o

pi.o: pi.c
	omcc -c pi.c 

run: 
	pi
