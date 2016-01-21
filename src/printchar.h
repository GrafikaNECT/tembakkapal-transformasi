#ifndef printchar_h
#define printchar_h

int initializePrinter();

int finishPrinter();

void printChar(char a, int X, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void printText(char* a, int alen, int X, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void printTextCentered(char* a, int alen, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void drawCanvas(unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void drawCharpixSquare(int _x, int _y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void setColor(unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

int getXRes();
int getYRes();

#endif
