all: build

comp: main.c lifegame.c matrixhelpers.c helpers.c
	gcc -Wall -c main.c lifegame.c matrixhelpers.c helpers.c -lrt

build: comp main.o lifegame.o matrixhelpers.o helpers.o
	gcc -Wall main.o lifegame.o matrixhelpers.o helpers.o -lrt

testAnimation: all
	clear
	./a.out 10 3 10 matrix.in testAnimation.out 1 0

test: all
	clear
	./a.out 10 3 10 matrix.in test.out 0 0

testQuiet: all
	clear
	./a.out 10 3 10 matrix.in testQuiet.out 0 1

testAnimation50: all
	clear
	./a.out 50 3 100 matrix.in testAnimation50.out 1 0

clear:
	rm -rf *.out *.o
