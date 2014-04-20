all: comp

comp: testReduce.c
	gcc -Wall testReduce.c -o testReduce.out

xeon: testReduce.c
	icc -Wall -mmic testReduce.c -o testReduce.out

clear:
	rm -rf *.o *.out
