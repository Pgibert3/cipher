#include <string.h>
#include "sim.c"

int main() {
    char* msg = "This is a test message. See if you can figure it out!";
    int rows = 6;
    int cols = 6;
    char* fname = "out.txt";

    printf("Encrypting message...\n");
    char** output = encode(rows, cols, msg);

    printf("Writing Encryption to file...\n");
    writetofile(rows, cols, output, fname);

    printf("Done.\n");
    free(output);
    return 0;
}
