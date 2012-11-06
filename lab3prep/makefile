all: xsum

xsum:xsum.o
	gcc -g -m32 -Wall -o xsum xsum.o
	rm -f *.o

xsum.o: xsum.c
	gcc -m32 -g -Wall -ansi -g -c -o xsum.o xsum.c

.PHONY : clean

clean:
	rm -f *.o
