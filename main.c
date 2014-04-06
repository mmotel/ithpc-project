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

int main(int argc, char **argv){
  // printf(" \033[2J\033[H");
  int n=6;
  int i,j;
  
  int **S = (int**) malloc( n * sizeof(int*));

  for(i=0; i<n; i++){
    S[i] = (int*) malloc(n * sizeof(int));
  }

  int **T = (int**) malloc( n * sizeof(int*));

  for(i=0; i<n; i++){
    T[i] = (int*) malloc(n * sizeof(int));
  }

  S[0][1] = 1;
  S[1][2] = 1;
  S[2][0] = 1;
  S[2][1] = 1;
  S[2][2] = 1;

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", S[i][j]);
    }  
    printf("\n");
  }

  makeMove(n, S, T);
// printf(" \033[2J\033[H");
  printf("\n");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", T[i][j]);
    }  
    printf("\n");
  }


  return 0;
}