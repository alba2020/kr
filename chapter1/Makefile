all: detab entab fold comments check

detab: detab.o
	cc detab.o -o detab
detab.o: ex_1_20.c
	cc -c ex_1_20.c -o detab.o

entab: entab.o
	cc entab.o -o entab
entab.o: ex_1_21.c
	cc -c ex_1_21.c -o entab.o

fold: fold.o
	cc fold.o -o fold
fold.o: ex_1_22.c
	cc -c ex_1_22.c -o fold.o

comments: comments.o
	cc comments.o -o comments
comments.o: ex_1_23.c
	cc -c ex_1_23.c -o comments.o

check: check.o
	cc check.o -o check
check.o: ex_1_24.c
	cc -c ex_1_24.c -o check.o

clean:
	rm *.o
