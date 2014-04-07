#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "matrixhelpers.h"

int checkCell(int x, int y, int size, int **S){
  int i,j;
  int count = 0;
  // printf("[%d, %d]\n", x,y);
  // printf("x:[%d, %d]\n", x-1,x+1);
  // printf("y:[%d, %d]\n", y-1,y+1);
  for(i = x-1; i <= x+1; i++){
    for(j = y-1; j <= y+1; j++){
      if((i >= 0) && (j >= 0) && (i < size) && (j < size)){
        // printf("[%d,%d] %d", i,j, S[i][j]);
        if(!(i==x && j==y) && S[i][j] == 1){
          // if(i==x && j==y){
          //   // printf("==");
          // }
          // else{
            count= count + 1;
            // printf("++");        
          // }

        }else{
          // printf("  ");
        }
      }
    }
    // printf("\n");
  }
  // printf("%d\n\n", count);
  return count;
}

void makeMove(int n, int **S, int **T){
  int i,j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      int count = checkCell(i,j, n, S);
      // T[i][j] = count;
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

  for(i=0; i < steps; i++){
    if(i%2==0){
      makeMove(n, S, T);
      if(printM == 1){
        //rintf(" \033[2J
          printf("\033[H");
        printMatrixAnimation(n, T);
        usleep(20);
      }
    }
    else{
      makeMove(n, T, S);
      if(printM == 1){
        //printf(" \033[2J
        printf("\033[H");
        printMatrixAnimation(n, S);
        usleep(20);
      }
    }
  }

  if(steps%2==0){
    R = S;
  }
  else{
    R = T;
  } 
}
