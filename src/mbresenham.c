///////HANYA UNTUK TESTING. BUKAN MAIN PROGRAM ======================

#include "bresenham.h"
#include "line-pattern.h"
#include "printchar.h"
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
#include <stdio.h>
int main(){
	initializePatterns();
	initializePrinter();
	drawCanvas(255,255,255,255);
	printToScreen();
	usleep(1000);

	bresenham_drawline(0,100,0,100,patternA);
	printToScreen();
	sleep(1);

	bresenham_drawline(0,100,100,50,patternA);
	printToScreen();
	sleep(1);

	drawCanvas(0,0,0,255);

	int x1,x2,y1,y2;

	y1 = 0;
	y2 = getYRes()-1;
	for (x1=0;x1<getXRes();x1++){
		x2 = getXRes()-x1-1;
		printf("%d,%d\n",x1,x2);
		bresenham_drawline(x1,x2,y1,y2,patternA);
		printToScreen();
		usleep(1000);
		bresenham_drawline(x1,x2,y1,y2,allBlack);
	}

	x1 = 0;
	x2 = getXRes()-1;
	for (y2=0;y2<getYRes();y2++){
		y1 = getYRes()-y2-1;
		bresenham_drawline(x1,x2,y1,y2,patternA);
		printToScreen();
		usleep(1000);
		bresenham_drawline(x1,x2,y1,y2,allBlack);
	}

}
