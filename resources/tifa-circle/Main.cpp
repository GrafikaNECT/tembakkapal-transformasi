#include "Circle.h"
#include "print.h"
#include <cstdlib>
#include <unistd.h>

int main() {
	if (initializePrinter()!=0) return 1;

	system("setterm -cursor off");

	drawCanvas(255,255,255,255);
	printToScreen();

	//drawPixSquare(5, 5, 5, 22, 22, 22, 255);

	Circle C = Circle(100,100,100,2);
	C.drawCircle(55,22,11,255, true, false);
	printToScreen();



	usleep(1000000);
	system("setterm -cursor on");
	finishPrinter();



	
	return 0;
}