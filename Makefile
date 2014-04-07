all: build

comp: main.c lifegame.c matrixhelpers.c
	gcc -Wall -c main.c lifegame.c matrixhelpers.c -lrt

build: comp main.o lifegame.o matrixhelpers.o
	gcc -Wall main.o lifegame.o matrixhelpers.o -lrt

testAnimation: all
	clear
	./a.out 10 10 matrix10.in 1

test: all
	clear
	./a.out 50 100 matrix50.in 0

testAnimation50: all
	clear
	./a.out 50 100 matrix50.in 1	

clear:
	rm -rf *.out *.o
