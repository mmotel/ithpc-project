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

//use: a.out #size #steps inFile outFile (0|1)printAnimation
int main(int argc, char **argv){
  if(argc < 4){
    printf("Użycie: a.out #size #steps startMatrixFile (0|1)printAnimation\n");
    return -1;
  }

  struct timespec s_input, e_input, start, end;
  struct timespec s_steps, e_steps, s_output, e_output;

  int n = atoi( argv[1] );
  int steps = atoi( argv[2] );
  int printM = atoi( argv[5] );

  int i;
  clock_gettime(CLOCK_MONOTONIC, &start);
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
  clock_gettime(CLOCK_MONOTONIC, &s_input);
  //read input state matrix from inFile
  fscanMatrix(n, argv[3], S);
  //print input state matrix
  if(printM == 1){
    printMatrixAnimation(n, S);
  }
  else{
    printMatrix(n, S);
  }
  clock_gettime(CLOCK_MONOTONIC, &e_input);
  
  if(printM == 1){
    printf(" \033[2J\033[H");
  }
  clock_gettime(CLOCK_MONOTONIC, &s_steps);
  //simulating steps
  simulateSteps(n, steps, S, T, R, printM);
  clock_gettime(CLOCK_MONOTONIC, &e_steps);
// printf(" \033[2J\033[H");


  clock_gettime(CLOCK_MONOTONIC, &s_output);
  //print result state matrix
  if(printM == 0){
    printMatrix(n, R);
  }
  //print result state matrix into outFile
  fprintMatrix(n, argv[4], R);
  clock_gettime(CLOCK_MONOTONIC, &e_output);

  //free allocated memmory
  for(i=0; i<n; i++){
    free(S[i]);
  }

  free(S);

  for(i=0; i<n; i++){
    free(T[i]);
  }  

  free(T);

  clock_gettime(CLOCK_MONOTONIC, &end);

  //print times
  printf("Time : %.16f\n", timeDiff(&end, &start));
  printf("Read : %.16f\n", timeDiff(&e_input, &s_input));
  printf("Steps: %.16f\n", timeDiff(&e_steps, &s_steps));
  printf("Write: %.16f\n", timeDiff(&e_output, &s_output));

  return 0;
}