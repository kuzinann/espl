.PHONY: all clean dist
.SUFFIXES: .c .o .h .asm

CFLAGS=-g -m32 -O0 -Wall
LDFLAGS=$(CFLAGS)


all: scmp cmpasm

%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc $(CFLAGS) -c $<

cmpasm: scmp.o cmpasm.o
	gcc $(LDFLAGS) -o cmpasm scmp.o cmpasm.o

scmp: scmp.o cmpstr.o 
	gcc $(LDFLAGS) -o scmp scmp.o cmpstr.o

clean:
	rm -f *.o *~

