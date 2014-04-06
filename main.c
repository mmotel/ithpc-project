#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "matrixhelpers.h"
#include "lifegame.h"

double timeDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  double diff = (((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
    ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec));
  return diff / 1000000000;
}

//use: a.out #size #steps inFile 
int main(int argc, char **argv){
  if(argc < 4){
    printf("Użycie: a.out #size #steps startMatrixFile (0|1)printAnimation\n");
    return -1;
  }

  struct timespec start, end;

  int n = atoi( argv[1] );
  int steps = atoi( argv[2] );
  int printM = atoi( argv[4] );

  int i;

  //allocating matrixes
  int **S = (int**) malloc( n * sizeof(int*));

  for(i=0; i<n; i++){
    S[i] = (int*) malloc(n * sizeof(int));
  }

  int **T = (int**) malloc( n * sizeof(int*));

  for(i=0; i<n; i++){
    T[i] = (int*) malloc(n * sizeof(int));
  }
  //---

  int **R = S;

  if(printM == 1){
    printf(" \033[2J\033[H");
  }

  //read input state matrix
  scanMatrix(n, argv[3], S);

  //print input state matrix
  if(printM == 1){
    printMatrixAnimation(n, S);
  }
  else{
    printMatrix(n, S);
  }
  
  if(printM == 1){
    printf(" \033[2J\033[H");
  }
  clock_gettime(CLOCK_MONOTONIC, &start);
  //simulating steps
  simulateSteps(n, steps, S, T, R, printM);
  clock_gettime(CLOCK_MONOTONIC, &end);
// printf(" \033[2J\033[H");

  //print result state matrix
  if(printM == 0){
    printMatrix(n, R);
  }

  printf("Time: %.16f\n", timeDiff(&end, &start));

  return 0;
}