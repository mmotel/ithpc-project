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

void printMatrix(int n, int **M){
  int i,j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", M[i][j]);
    }  
    printf("\n");
  }
  printf("\n");
}

void scanMatrix(int n, char *fname, int **M){
  int i,j;
  FILE *inputfile = fopen(fname, "r");

  if(inputfile == NULL){
    printf("Nie można otworzyć pliku\n");
    exit(1);
  }

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      // printf("[%d,%d] ", i,j);
      fscanf(inputfile, "%d", &M[i][j]);
    }  
    // printf("\n");
  }

  fclose(inputfile);
}

//use: a.out #size #steps inFile 
int main(int argc, char **argv){
  // printf(" \033[2J\033[H");

  if(argc < 3){
    printf("Użycie: a.out #size #steps startMatrixFile\n");
    return -1;
  }

  int n = atoi( argv[1] );
  int steps = atoi( argv[2] );

  int i,j;

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
  // FILE *inputfile = fopen(argv[3], "r");

  // if(inputfile == NULL){
  //   printf("Nie można otworzyć pliku\n");
  //   return -1;
  // }

  // for(i = 0; i < n; i++){
  //   for(j = 0; j < n; j++){
  //     // printf("[%d,%d] ", i,j);
  //     fscanf(inputfile, "%d", &S[i][j]);
  //   }  
  //   // printf("\n");
  // }

  // fclose(inputfile);
  scanMatrix(n, argv[3], S);
  //---

  //print input state matrix
  printMatrix(n, S);

  //simulating steps
  simulateSteps(n, steps, S, T, R);

// printf(" \033[2J\033[H");

  //print result state matrix
  printMatrix(n, R);


  return 0;
}