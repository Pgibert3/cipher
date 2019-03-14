#include <stdio.h>
#include <stdlib.h>

char** encode(int rows, int cols, char* msg);
int writetofile(int tot_rows, int tot_cols, char** data, char* fname);
