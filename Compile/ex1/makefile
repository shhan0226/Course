foo: foo.o prt.o
	cc -o foo foo.o prt.o

prt.o: prt.c
	cc -c prt.c

foo.o: foo.c
	cc -c foo.c

clean:
	rm *.o

run:
	foo
	echo $?
