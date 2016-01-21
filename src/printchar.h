#ifndef printchar_h
#define printchar_h

int initializePrinter();

int finishPrinter();

void printChar(char a, int X, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void printText(char* a, int alen, int X, int Y, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void hapusScreen();

#endif
