all:
	gcc -Wall main.c 

test: all
	./a.out