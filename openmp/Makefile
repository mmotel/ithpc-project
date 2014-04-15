all: build

#LD_LIBRARY_PATH=./ ./a.out 1000 3 10000 matrix.in testBig2.out 0 0 1

xeonc: main.c lifegame.c ../lib/helpers.c
	icc -mmic -Wall -c -fpic  main.c lifegame.c ../lib/helpers.c -lrt -fopenmp -L/home/tadeusz/intel/composer_xe_2013_sp1.2.144/compiler/lib/mic

xeonb: xeonc main.o lifegame.o helpers.o
	icc -mmic -Wall main.o lifegame.o helpers.o -lrt -fopenmp -L/home/tadeusz/intel/composer_xe_2013_sp1.2.144/compiler/lib/mic

xeon: xeonb
	scp a.out mic0:/home/inf/mm194919/ithpc

comp: main.c lifegame.c ../lib/helpers.c
	gcc -Wall -fopenmp -c main.c lifegame.c ../lib/helpers.c -lrt

build: comp main.o lifegame.o helpers.o
	gcc -Wall -fopenmp main.o lifegame.o helpers.o -lrt

testAnimation: all
	clear
	./a.out 10 3 10 matrix.in testAnimation.out 1 0 0

test: all
	clear
	./a.out 10 3 10 matrix.in test.out 0 1 0

testBig:
	clear
	touch testBig.out
	rm testBig.out
	./a.out 1000 3 1500 matrix.in testBig.out 0 0 1

testQuiet: all
	clear
	./a.out 10 3 10 matrix.in testQuiet.out 0 1 1

testAnimation50: all
	clear
	./a.out 50 3 100 matrix.in testAnimation50.out 1 0 0

clear:
	rm -rf *.out *.o
