#ifndef image_h
#define image_h

#include <stdbool.h>
#include <stdio.h>

void drawCharpixSquare(int _x, int _y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);
void setColor(unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);
void drawPicture(int _x, int _y, int size);

#endif
