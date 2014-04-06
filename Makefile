all: main.c
	gcc -Wall main.c 

test: all
	clear
	./a.out 10 5 matrix.in
