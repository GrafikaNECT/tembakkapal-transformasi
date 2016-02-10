#include "kapallaut.h"
#include "print.h"
#include "char.h"
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	int space = 2;
	int i;

	if (initializePrinter()!=0) return 0;

	system("setterm -cursor off");

	drawCanvas(0,0,0,255);
	printToScreen();

	usleep(10000);
	kapallaut* kapal = new kapallaut(0,0,255);
	
	printToScreen();

	usleep(1000000);
	delete kapal;

	system("setterm -cursor on");
	finishPrinter();
}
