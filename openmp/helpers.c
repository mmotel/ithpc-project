#include <stdio.h>
#include <stdlib.h>

//helpers
void fprintTimes(char *fname, double timeAll, double timeRead, double timeSteps, double timeWrite){
  FILE *outputfile = fopen(fname, "a");

  fprintf(outputfile, "Time : %.16f\n", timeAll);
  fprintf(outputfile, "Read : %.16f\n", timeRead);
  fprintf(outputfile, "Steps: %.16f\n", timeSteps);
  fprintf(outputfile, "Write: %.16f\n", timeWrite);

  fclose(outputfile);
}

void printTimes(double timeAll, double timeRead, double timeSteps, double timeWrite){
  printf("Time : %.16f\n", timeAll);
  printf("Read : %.16f\n", timeRead);
  printf("Steps: %.16f\n", timeSteps);
  printf("Write: %.16f\n", timeWrite);
}

double timeDiff(struct timespec *timeA_p, struct timespec *timeB_p){
  double diff = (((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
    ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec));
  return diff / 1000000000;
}

//matrix helpers
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