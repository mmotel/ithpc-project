#include <stdio.h>
#include <stdlib.h>

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

void simulateSteps(int n, int steps, int **S, int **T, int **R){
  int i;

  for(i=0; i < steps; i++){
    if(i%2==0){
      makeMove(n, S, T);
      // printMatrix(n, T);
    }
    else{
      makeMove(n, T, S);
      // printMatrix(n, S);
    }
  }

  if(steps%2==0){
    R = S;
  }
  else{
    R = T;
  } 
}