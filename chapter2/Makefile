all: limits maxline

limits: limits.o
	cc limits.o -o limits
limits.o: ex_2_1.c
	cc -c ex_2_1.c -o limits.o

maxline: maxline.o
	cc maxline.o -o maxline
maxline.o: ex_2_2.c
	cc -c ex_2_2.c -o maxline.o


clean:
	rm *.o
