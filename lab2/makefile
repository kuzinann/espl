all: testnl testfgn canalyze

test: testnl testfgn	./testnl	./testfgn

canalyze: canalyze.o fgetname.o namelist.o

testnl: testnl.o namelist.o
testfgn: testfgn.o fgetname.o

canalyze.o : canalyze.c
testnl.o: testnl.c namelist.h
namelist.o: namelist.c namelist.h

testfgn.o: testfgn.c fgetname.h
fgetname.o: fgetname.c fgetname.h

clean:	rm	-f	testnl	testfgn	*.o
