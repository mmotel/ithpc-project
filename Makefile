all: build

comp: main.c lifegame.c matrixhelpers.c
	gcc -Wall -c main.c lifegame.c matrixhelpers.c -lrt

build: comp main.o lifegame.o matrixhelpers.o
	gcc -Wall main.o lifegame.o matrixhelpers.o -lrt

testAnimation: all
	clear
	./a.out 10 10 matrix.in 1

test: all
	clear
	./a.out 10 10 matrix.in 0

clear:
	rm -rf *.out *.o
