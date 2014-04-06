all: build

comp: main.c lifegame.c matrixhelpers.c
	gcc -Wall -c main.c lifegame.c matrixhelpers.c

build: comp
	gcc -Wall main.o lifegame.o matrixhelpers.o

test: all
	clear
	./a.out 10 10 matrix.in

clear:
	rm -rf *.out *.o
