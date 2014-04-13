#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "helpers.h"
#include "lifegame.h"

//use: a.out #size #steps inFile outFile (0|1)printAnimation (0|1)quiet
int main(int argc, char **argv){
  if(argc < 8){
    printf("Użycie: a.out #size #inputSize #steps startMatrixFile resultMatrixFile (0|1)printAnimation (0|1)printMatrix (0|1)quiet\n");
    return -1;
  }

  struct timespec s_input, e_input, start, end;
  struct timespec s_steps, e_steps, s_output, e_output;

  int i;
  int **R;

  double timeAll, timeInput, timeSteps, timeWrite;

  int n = atoi( argv[1] );
  int in = atoi( argv[2] );
  int steps = atoi( argv[3] );
  char *inFile = argv[4];
  char *outFile = argv[5];
  int printAnim = atoi( argv[6] );
  int printMat = atoi( argv[7] );
  int quiet = atoi( argv[8] );


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

  R = S;

  if(quiet != 1 && printAnim == 1){
    printf(" \033[2J\033[H");
  }


  //read input state matrix from inFile  
  clock_gettime(CLOCK_MONOTONIC, &s_input);

  fscanMatrix(in, inFile, S);

  //print input state matrix
  if(quiet != 1 && printAnim == 1){
    printMatrixAnimation(n, S);
    printf(" \033[2J\033[H");
  }
  else if(quiet != 1){
    printMatrix(n, S);
  }

  clock_gettime(CLOCK_MONOTONIC, &e_input);


  //simulating steps
  clock_gettime(CLOCK_MONOTONIC, &s_steps);

  simulateSteps(n, steps, S, T, R, printAnim);

  clock_gettime(CLOCK_MONOTONIC, &e_steps);


  //print result state matrix
  clock_gettime(CLOCK_MONOTONIC, &s_output);

  if(quiet != 1 && printAnim == 0){
    printMatrix(n, R);
  }
  //print result state matrix into outFile
  if(printMat == 1){
    fprintMatrix(n, outFile, R);
  }
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

  timeAll = timeDiff(&end, &start);
  timeInput = timeDiff(&e_input, &s_input);
  timeSteps = timeDiff(&e_steps, &s_steps);
  timeWrite = timeDiff(&e_output, &s_output);

  //print times
  if(quiet != 1){
    printTimes(timeAll, timeInput, timeSteps, timeWrite);
  }
  fprintTimes(outFile, timeAll, timeInput, timeSteps, timeWrite);

  return 0;
}