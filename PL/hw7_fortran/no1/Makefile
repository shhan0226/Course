no1: no1.o no1_c.o
	pgf90 -o no1 no1.o no1_c.o

no1.o: no1.F
	pgf90 -c no1.F

no1_c.o: no1_c.c
	pgcc -c no1_c.c

clean:
	rm *.o
