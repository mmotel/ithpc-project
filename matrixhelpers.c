#include <stdio.h>
#include <stdlib.h>

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

void printMatrixAnimation(int n, int **M){
  int i,j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(M[i][j] == 1){
        printf("# ");
      }
      else{
        printf("- ");
      }
      // printf("%d ", M[i][j]);
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