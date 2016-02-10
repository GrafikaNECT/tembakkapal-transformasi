#include "cannon.h"
#include "print.h"

int main() {
	if (initializePrinter()!=0) return 0;
	drawCanvas(0,0,0,255);
	int x,y;
	y = getYRes()/2;
	x = getXRes()/2;
	cannon C(x,y);
	C.draw();
	printToScreen();
	finishPrinter();
	return 0; 
}