all: build

comp: main.c lifegame.c matrixhelpers.c
	gcc -Wall -c main.c lifegame.c matrixhelpers.c -lrt

build: comp main.o lifegame.o matrixhelpers.o
	gcc -Wall main.o lifegame.o matrixhelpers.o -lrt

testAnimation: all
	clear
	./a.out 10 3 10 matrix.in testAnimation.out 1

test: all
	clear
	./a.out 10 3 10 matrix.in test.out 0

testAnimation50: all
	clear
	./a.out 50 3 100 matrix.in testAnimation50.out 1	

clear:
	rm -rf *.out *.o
