all:	main.o lex.yy.o parser.o
	gcc -o parser main.o lex.yy.o parser.o

main.o: lex.h main.c
	gcc -c main.c

parser.o:lex.h parser.c
	gcc -c parser.c

lex.yy.o:lex.h lex.l lex.yy.c
	gcc -c lex.yy.c

lex.yy.c:lex.h lex.l
	lex lex.l

clean:
	rm -f *.o lex.yy.c
