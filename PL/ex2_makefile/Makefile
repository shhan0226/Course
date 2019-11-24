foo: foo1.o prt1.o
	ld -o foo foo1.o prt1.o /usr/lib64/crt1.o /usr/lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/4.1.2/crtbegin.o /usr/lib/gcc/x86_64-redhat-linux/4.1.2/crtend.o /usr/lib64/crtn.o -I/lib64/ld-linux-x86-64.so.2 -L/usr/lib64 -lc

prt1.o: prt1.c
	cc -c prt1.c
prt1.c : prt.c
	cpp prt.c >prt1.c


foo1.o: foo1.c
	cc -c foo1.c
foo1.c : foo.c
	cpp foo.c > foo1.c

clean:
	rm -f prt1.c foo1.c *.o

run: 
	foo
	echo $?
