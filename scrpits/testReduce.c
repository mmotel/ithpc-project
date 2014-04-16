#include <stdio.h>
#include <stdlib.h>

// ./testReduce.out file.times #n
int main(int argc, char **argv){

  if(argc < 3){
    printf("Użycie: ./testReduce.out file.times #n\n");
    return -1;
  }

  char *fname = argv[1];
  int n = atoi( argv[2] );

  double time_avrg = 0;
  double time_temp = 0;
  double time_sum = 0;
  
  double read_avrg = 0;
  double read_temp = 0;
  double read_sum = 0;
  
  double steps_avrg = 0;
  double steps_temp = 0;
  double steps_sum = 0;

  double write_avrg = 0;
  double write_temp = 0;
  double write_sum = 0;

  int i;


  FILE *f;

  f = fopen(fname, "r");

  for(i=0; i < n; i++){
    fscanf(f, "%lf\n", &time_temp);
    time_sum += time_temp;

    fscanf(f, "%lf\n", &read_temp);
    read_sum += read_temp;

    fscanf(f, "%lf\n", &steps_temp);
    steps_sum += steps_temp;

    fscanf(f, "%lf\n", &write_temp);
    write_sum += write_temp;
  }

  fclose(f);

  time_avrg = time_sum / (double) n;

  read_avrg = read_sum / (double) n;

  steps_avrg = steps_sum / (double) n;

  write_avrg = write_sum / (double) n;

  printf(" avrg time  = ( %.16f )\n", time_avrg);
  printf(" avrg read  = ( %.16f )\n", read_avrg);
  printf(" avrg steps = ( %.16f )\n", steps_avrg);
  printf(" avrg write = ( %.16f )\n", write_avrg);

  return 0;
}