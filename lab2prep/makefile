all: fortune

fortune:fortune.o
	gcc -g -m32 -Wall -o fortune fortune.o
	rm -f *.o

fortune.o: fortune.c
	gcc -m32 -g -Wall -ansi -g -c -o fortune.o fortune.c

.PHONY : clean

clean:
	rm -f *.o
