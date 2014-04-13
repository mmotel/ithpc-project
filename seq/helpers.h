//helpers
void fprintTimes(char *fname, double timeAll, double timeRead, double timeSteps, double timeWrite);
void printTimes(double timeAll, double timeRead, double timeSteps, double timeWrite);
double timeDiff(struct timespec *timeA_p, struct timespec *timeB_p);
//matrix helpers
void printMatrix(int n, int **M);
void printMatrixAnimation(int n, int **M);
void fscanMatrix(int n, char *fname, int **M);
void fprintMatrix(int n, char *fname, int **M);