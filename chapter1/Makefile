all: detab entab fold

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

clean:
	rm *.o
