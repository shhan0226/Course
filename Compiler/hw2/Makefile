scan2:	main.o lex.yy.o
	gcc -o scan2 main.o lex.yy.o

main.o:	lex.h main.c
	gcc -c main.c

lex.yy.o:lex.h lex.l
	lex lex.l
	gcc -c lex.yy.c

clean:
	rm -f *.o lex.yy.c
