#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "matrixhelpers.h"

int checkCell(int x, int y, int size, int **S){
  int i,j;
  int count = 0;

  for(i = x-1; i <= x+1; i++){
    for(j = y-1; j <= y+1; j++){
      if((i >= 0) && (j >= 0) && (i < size) && (j < size)){
        if(!(i == x && j == y) && S[i][j] == 1){
          count = count + 1;
        }
      }
    }
  }
  return count;
}

void makeMove(int n, int **S, int **T){
  int i,j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      int count = checkCell(i,j, n, S);

      if((count == 2 || count == 3) && S[i][j] == 1){
        T[i][j] = 1;
      }
      else if(count == 3 && S[i][j] == 0){
        T[i][j] = 1;
      }
      else{
        T[i][j] = 0;
      }
    }
  }
}

void simulateSteps(int n, int steps, int **S, int **T, int **R, int printM){
  int i;

  for(i = 0; i < steps; i++){
    if(i%2 == 0){
      makeMove(n, S, T);
      if(printM == 1){
        printf("\033[H");
        printMatrixAnimation(n, T);
        usleep(50);
      }
    }
    else{
      makeMove(n, T, S);
      if(printM == 1){
        printf("\033[H");
        printMatrixAnimation(n, S);
        usleep(50);
      }
    }
  }

  if(steps%2 == 0){
    R = S;
  }
  else{
    R = T;
  } 
}
