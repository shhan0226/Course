cexpr: main.o y.tab.o lex.yy.o csym.o cword.o
	gcc -o cexpr main.o y.tab.o lex.yy.o csym.o cword.o 

csym.o: 
	gcc -c csym.c

cword.o:
	gcc -c cword.c

main.o:
	gcc -c main.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: gram.y
	yacc -d gram.y

lex.yy.o: lex.l lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: lex.l
	lex lex.l

clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h
	
