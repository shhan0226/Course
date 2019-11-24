saxpy: saxpy.o millisecond.o
	omcc -o saxpy saxpy.o -lmillisecond -L.

millisecond.o: millisecond.c
	omcc -c millisecond.c
	ar -cr libmillisecond.a millisecond.o

saxpy.o: saxpy.c
	omcc -c saxpy.c

clear:
	rm *.o
