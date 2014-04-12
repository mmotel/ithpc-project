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
    }  
    printf("\n");
  }
  printf("\n");
}

void fscanMatrix(int n, char *fname, int **M){
  int i,j;
  FILE *inputfile = fopen(fname, "r");

  if(inputfile == NULL){
    printf("Nie można otworzyć pliku\n");
    exit(1);
  }

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      fscanf(inputfile, "%d", &M[i][j]);
    }  
  }

  fclose(inputfile);
}

void fprintMatrix(int n, char *fname, int **M){
  int i,j;

  FILE *outputfile = fopen(fname, "w");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      fprintf(outputfile, "%d ", M[i][j]);
    }  
    fprintf(outputfile, "\n");
  }
  fprintf(outputfile, "\n");

  fclose(outputfile);
}