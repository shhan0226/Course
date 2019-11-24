parser:	main.o y.tab.o lex.yy.o
	gcc -o parser main.o y.tab.o lex.yy.o

main.o:
	gcc -c main.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: gram.y
	yacc -d gram.y

lex.yy.o:lex.l lex.yy.c
	gcc -c lex.yy.c

lex.yy.c:lex.l
	lex lex.l

clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h
