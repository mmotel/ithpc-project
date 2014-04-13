#include <stdio.h>
#include <stdlib.h>

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