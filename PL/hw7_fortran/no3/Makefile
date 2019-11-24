no3: no3.o no3_c.o
	pgf90 -o no3 no3.o no3_c.o

no3.o: no3.F
	pgf90 -c no3.F

no3_c.o: no3_c.c
	pgcc -c no3_c.c

clean:
	rm *.o
