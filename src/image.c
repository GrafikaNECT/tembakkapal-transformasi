#include <stdio.h>
#include "image.c"

char fileName[50] = "binarytest.txt";
int R1 = 0; int G1 = 10; int B1 = 30;
int R2 = 30; int G2 = 30; int B2 = 30;
int R3 = 50; int G3 = 40; int B3 = 10;
int R4 = 50; int G4 = 60; int B4 = 40;
int R5 = 40; int G5 = 0; int B5 = 10;

void drawPicture(int _x, int _y, int size) {
    char const* const fileName = argv[1]; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); 
    }
    
    fclose(file);
}
