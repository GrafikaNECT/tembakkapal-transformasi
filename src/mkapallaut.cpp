#include "kapallaut.h"
#include "printchar.h"
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
	kapallaut kapal = kapallaut(0,0);
	drawPicture(50,50,15,200,"ship.txt");

	printToScreen();

	usleep(1000000);

	system("setterm -cursor on");
	finishPrinter();
}