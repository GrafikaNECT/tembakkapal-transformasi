#include "letter.h"
#include "print.h"
#include "pixelBoolMatrix.h"


#include <unistd.h>

#include <vector>

#include <iostream>

#include <stdlib.h>

int main(){
	system("setterm -cursor on");

	//coba bikin huruf terus print

	//bikin huruf A kebalik
	polygon p;
	p.push_back(0,0);
	p.push_back(4,12);
	p.push_back(8,0);
	p.push_back(7,0);
	p.push_back(6,3);
	p.push_back(2,3);
	p.push_back(1,0);

	std::vector<polygon> bidangs;
	bidangs.push_back(p);

	polygon p2;
	p2.push_back(3,5);
	p2.push_back(4,10);
	p2.push_back(5,5);

	std::vector<polygon>lubangs;
	lubangs.push_back(p2);

// Ini mau implementasi teks
	letter letterAKebalik(bidangs,lubangs,9,13);
	initializePrinter();
	pixelBoolMatrix pbm1 = letterAKebalik.toPixelBoolMatrix(1);

	drawCanvas(0,0,0,255);
	pbm1.draw(10,10,255,255,255,255);
	printToScreen();
	sleep(1);
// Akhir


	for (int i=0;i<100;i++){
		pixelBoolMatrix pbm = letterAKebalik.toPixelBoolMatrix(1+(float)i/10);
		drawCanvas(0,0,0,255);
		pbm.draw(10,10,255,255,255,255);
		printToScreen();
		usleep(1000);

	}
	finishPrinter();
	system("setterm -cursor on");
	
}
