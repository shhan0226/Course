wc: main.o wc.o
	gcc -o wc2 main.o wc.o

main.o: main.c
	gcc -c main.c

wc.o: wc.c
	gcc -c wc.c

clean:
	rm -f *.o wc2
