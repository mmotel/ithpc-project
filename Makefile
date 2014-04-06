all: main.c
	gcc -Wall main.c 

test: all
	clear
	./a.out
