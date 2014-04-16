all: build

comp: main.c lifegame.c ../lib/helpers.c
	gcc -Wall -c main.c lifegame.c ../lib/helpers.c -lrt

build: comp main.o lifegame.o helpers.o
	gcc -Wall main.o lifegame.o helpers.o -lrt

testAnimation: all
	clear
	./a.out 10 3 10 ../matrix.in testAnimation.out 1 0 0

test: all
	clear
	./a.out 10 3 10 ../matrix.in test.out 0 1 0

testBig: all
	clear
	touch testBig.out
	rm testBig.out
	./a.out 1000 3 1500 ../matrix.in testBig.out 0 0 1

testQuiet: all
	clear
	./a.out 10 3 10 ../matrix.in testQuiet.out 0 1 1

testAnimation50: all
	clear
	./a.out 50 3 100 ../matrix.in testAnimation50.out 1 0 0

clear:
	rm -rf *.out *.o *.out.times
