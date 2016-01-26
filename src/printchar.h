#ifndef printchar_h
#define printchar_h

int initializePrinter();

int finishPrinter();

void drawChar(char a, int X, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void drawText(char* a, int alen, int X, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void drawTextCentered(char* a, int alen, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void drawCanvas(unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void drawPix(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void drawCharpixSquare(int _x, int _y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void setColor(unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void drawCatPicture(int _x, int _y, int size, int max_X);

void printToScreen();

int getXRes();
int getYRes();

#endif
