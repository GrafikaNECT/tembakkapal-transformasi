#include "circle.h"
#include "print.h"
#include <unistd.h>

int main(){
	initializePrinter();
	drawCanvas(0,0,0,255);
	int x,y;
	y = getYRes()/2;
	x = getXRes()/2;
	circle C = makeCircle(0,0,0,255,20,x,y);
	for (i=0;i<=360;i++) {
		rotateCircle(C,i,x,y);
		drawCircle(C);
	}
	printToScreen();
	finishPrinter();
}
