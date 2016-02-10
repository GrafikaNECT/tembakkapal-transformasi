#include "line-pattern.h"
#include "print.h"
#include <unistd.h>

line_pattern patternA;

line_pattern allBlack;

void initializePatterns(){
	unsigned char AR [] = {255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	unsigned char AG [] = {0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0};
	unsigned char AB []= {0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0};
	unsigned char AAlpha []= {255, 255, 255, 255, 0, 255, 255, 255, 255, 0, 255, 255, 255, 255, 0};
	patternA = makeLinePattern(AR,AG,AB,AAlpha , 15);
	unsigned char AllBlackR [] ={0};
	unsigned char AllBlackG[] ={0};
	unsigned char AllBlackB[] ={0};
	unsigned char AllBlackA[] ={255};
	
	allBlack = makeLinePattern(AllBlackR,AllBlackG,AllBlackB,AllBlackA,1);
}

int main(){
	initializePrinter();
	initializePatterns();
	drawCanvas(0,0,0,255);
	int x,y;
	y = getYRes()/2;
	init_line_pattern(patternA);
	for (x=0;x<getXRes();x++){
		printToScreen();
		usleep(1000);
		line_pattern_plot(x,y);
	}
	init_line_pattern(allBlack);
	for (x=0;x<getXRes();x++){
		printToScreen();
		usleep(1000);
		line_pattern_plot(x,y);
	}
	printToScreen();
	finishPrinter();
}
