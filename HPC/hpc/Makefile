ex2: ex2.o millisecond.o
	cc -o hw1 hw1.o -lmillisecond -L.

millisecond.o: millisecond.c
	cc -c millisecond.c
	ar -cr libmillisecond.a millisecond.o

ex2.o: ex2.c
	cc -c hw1.c

clear:
	rm *.o
