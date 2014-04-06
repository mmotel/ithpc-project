#include <stdio.h>
#include <stdlib.h>

#include "matrixhelpers.h"
#include "lifegame.h"

//use: a.out #size #steps inFile 
int main(int argc, char **argv){
  // printf(" \033[2J\033[H");

  if(argc < 3){
    printf("Użycie: a.out #size #steps startMatrixFile\n");
    return -1;
  }

  int n = atoi( argv[1] );
  int steps = atoi( argv[2] );

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

  //read input state matrix
  scanMatrix(n, argv[3], S);

  //print input state matrix
  printMatrix(n, S);

  //simulating steps
  simulateSteps(n, steps, S, T, R);

// printf(" \033[2J\033[H");

  //print result state matrix
  printMatrix(n, R);


  return 0;
}