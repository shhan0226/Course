ex3: ex3.o ex3_c.o
	pgf90 -o ex3 ex3.o ex3_c.o

ex3.o: ex3.F
	pgf90 -c ex3.F

ex3_c.o: ex3_c.c
	pgcc -c ex3_c.c

clean:
	rm *.o
