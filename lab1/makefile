all: task1

task1: task1.o
	gcc -g -m32 -Wall -o task1 task1.o
	rm -f *.o

task1.o: task1.c
	gcc -m32 -g -Wall -ansi -g -c -o task1.o task1.c

.PHONY : clean

clean:
	rm -f *.o
