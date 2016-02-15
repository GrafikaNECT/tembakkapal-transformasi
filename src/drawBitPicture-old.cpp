#include "drawBitPicture-old.h"
#include "print.h"

#include <iostream>
#include <cstdio>
#include <cstring>

void drawCatPicture(int _x, int _y, int size, int max_X) {
    int alpha = 255;
    int R0 = 0; int G0 = 0; int B0 = 0;
    int R1 = 178; int G1 = 151; int B1 = 204;
    int R2 = 226; int G2 = 226; int B2 = 226;
    int R3 = 250; int G3 = 249; int B3 = 184;
    int R4 = 251; int G4 = 255; int B4 = 255;
    int R5 = 255; int G5 = 202; int B5 = 207;
    int R,G,B;
    int i;
    int x,y;

    y = _y;

    char const* const fileName = "cat_pixel.txt";
    FILE* file = fopen(fileName, "r"); /* should check the result */
    char line[max_X+1];

    while (fgets(line, sizeof(line), file)) {
        char* tmp = line;
        x = _x;
        for (i = 0; i < strlen(tmp); i++) {
            switch(tmp[i]){
                case '0':
                    R = R0; G = G0; B = B0;
                    drawPixSquare(x, y, size, R, G, B, alpha);
                    break;
                case '1':
                    R = R1; G = G1; B = B1;
                    drawPixSquare(x, y, size, R, G, B, alpha);
                    break;
                case '2':
                    R = R2; G = G2; B = B2;
                    drawPixSquare(x, y, size, R, G, B, alpha);
                    break;
                case '3':
                    R = R3; G = G3; B = B3;
                    drawPixSquare(x, y, size, R, G, B, alpha);
                    break;
                case '4':
                    R = R4; G = G4; B = B4;
                    drawPixSquare(x, y, size, R, G, B, alpha);
                    break;
                case '5':
                    R = R5; G = G5; B = B5;
                    drawPixSquare(x, y, size, R, G, B, alpha);
                    break;
                
            }
            x+=size;
        }
        y+=size;
    }
    
    fclose(file);
}

int R[10];
int G[10];
int B[10];

void getColor (char* fileName) {
    FILE* file = fopen (fileName, "r");
    int num = 0;
    int i = 0;

    while (!feof (file)) {  
        fscanf (file, "%d", &num);   
        R[i] = num;
        fscanf (file, "%d", &num);   
        G[i] = num;
        fscanf (file, "%d", &num);   
        B[i] = num;
        i++;
    }

    fclose (file);
}

void printRGB () {
    for (int i = 0; i < 3; i++) {
        printf("R: %d, G: %d, B: %d\n",R[i],G[i],B[i]);
    }
}

void drawPicture(int _x, int _y, int size, int max_X, char* fileName,char* fileColor) {
    int alpha = 255;
    getColor(fileColor);
    int Rfix,Gfix,Bfix;
    int i;
    int x,y;

    y = _y;

    FILE* file = fopen(fileName, "r"); /* should check the result */
    char line[max_X+1];

    while (fgets(line, sizeof(line), file)) {
        char* tmp = line;
        x = _x;
        for (i = 0; i < strlen(tmp); i++) {
            switch(tmp[i]){
                case '0':
                    Rfix = R[0]; Gfix = G[0]; Bfix = B[0];
                    drawPixSquare(x, y, size, Rfix, Gfix, Bfix, 0);
                    break;
                case '1':
                    Rfix = R[1]; Gfix = G[1]; Bfix = B[1];
                    drawPixSquare(x, y, size, Rfix, Gfix, Bfix, alpha);
                    break;
                case '2':
                    Rfix = R[2]; Gfix = G[2]; Bfix = B[2];
                    drawPixSquare(x, y, size, Rfix, Gfix, Bfix, alpha);
                    break;
                case '3':
                    Rfix = R[3]; Gfix = G[3]; Bfix = B[3];
                    drawPixSquare(x, y, size, Rfix, Gfix, Bfix, alpha);
                    break;
                case '4':
                    Rfix = R[4]; Gfix = G[4]; Bfix = B[4];
                    drawPixSquare(x, y, size, Rfix, Gfix, Bfix, alpha);
                    break;
                case '5':
                    Rfix = R[5]; Gfix = G[5]; Bfix = B[5];
                    drawPixSquare(x, y, size, Rfix, Gfix, Bfix, alpha);
                    break;
                case '6':
                    Rfix = R[6]; Gfix = G[6]; Bfix = B[6];
                    drawPixSquare(x, y, size, Rfix, Gfix, Bfix, alpha);
                    break;
                
            }
            x+=size;
        }
        y+=size;
    }
    
    fclose(file);
}
