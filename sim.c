#include "sim.h"

char** encode(int tot_rows, int tot_cols, char* msg) {
    if (tot_rows < 1) {
        printf("must have at least one row\n");
        return NULL;
    }
    if (tot_cols < 1) {
        printf("must have at least one collumn\n");
        return NULL;
    }

    char** output = (char**) malloc(sizeof(char*) * tot_rows);
    if (output == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    for (int i = 0; i < tot_cols; i++) {
        output[i] = malloc(sizeof(char) * tot_cols);
        if (output[i] == NULL) {
            printf("malloc failed\n");
            return NULL;
        }
    }

    int end_of_msg = 0;
    for (int row_c = tot_rows - 1; row_c >= 0; row_c--) {
        int c = 0;
        int r = row_c;
        int col_c = 0;

        while (col_c < tot_cols) {
            if (!end_of_msg && (*msg == 0)) {
                end_of_msg = 1;
            }

            if (r < tot_rows && c < tot_cols) {
                if (end_of_msg) {
                    output[r][c] = '0';
                    printf("(%d,%d): %c | %c\n", r, c, '0', *msg);
                } else {
                  output[r][c] = *msg;
                  printf("(%d,%d): %c\n", r, c, *msg);
                  msg++;
                }
                c++;
                r++;
            } else {
                col_c++;
                r = row_c;
                c = col_c;
            }
        }
    }

    return output;
}

int writetofile(int tot_rows, int tot_cols, char** data, char* fname) {
    FILE* fp = fopen(fname, "w+");
    if (fp == NULL) {
        printf("failed to access file\n");
        return 1;
    }
    for (int r = 0; r < tot_rows; r++) {
        fputs(data[r], fp);
        fputs("\n", fp);
    }

    fclose(fp);

    return 0;
}
