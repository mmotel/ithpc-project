void fprintTimes(char *fname, double timeAll, double timeRead, double timeSteps, double timeWrite);
void printTimes(double timeAll, double timeRead, double timeSteps, double timeWrite);
double timeDiff(struct timespec *timeA_p, struct timespec *timeB_p);