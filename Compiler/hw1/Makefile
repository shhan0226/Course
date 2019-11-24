scan2:	main.o lex.o
	gcc -o scan2 main.o lex.o

main.o:	lex.h main.c
	gcc -c main.c

lex.o:	lex.h lex.c
	gcc -c lex.c

clean:
	rm -f *.o
