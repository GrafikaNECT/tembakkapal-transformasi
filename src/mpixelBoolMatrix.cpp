#include "pixelBoolMatrix.h"
#include "polygon.h"
#include "print.h"

#include <unistd.h>
#include <iostream>
int main(){
	initializePrinter();

	polygon p;
	p.push_back(4,4);
	p.push_back(30,100);
	p.push_back(100,4);
	p.push_back(30,400);

	drawCanvas(0,0,0,255);
	pixelBoolMatrix mat(1000,1000);
	mat.setWireframe(p,true);
	mat.draw(10,10,255,255,255,255);
	printToScreen();
	sleep(1);
/*
	mat.fill(30,200,true);
	drawCanvas(0,0,0,255);
	mat.draw(10,10,255,255,255,255);
	printToScreen();
	sleep(1);
	std::cout<<"check\n"<<std::endl;
*/
	drawCanvas(0,0,0,255);
	mat.setAll(false);
	mat.setSolid(p,true);
	mat.draw(10,10,255,255,255,255);
	printToScreen();
	sleep(1);

	drawCanvas(0,0,0,255);
	mat.setAll(false);
	mat.setSolid(p,true);
	mat.draw(-1,-1,255,255,255,255);
	printToScreen();
	sleep(1);

	pixelBoolMatrix mat2(100,100);
	mat.setAll(true);
	mat.draw(500,500,255,255,255,255);
	printToScreen();

	usleep(1000);

	pixelBoolMatrix mattt(getXRes(),getYRes());
	for (int i=0;i<100;i++){

		drawCanvas(0,0,0,255);
		std::cout<<i<<std::endl;
		polygon p_resize = p.hasilPerbesar(1+(float)i/40);
		std::cout<<"check"<<std::endl;
		std::cout<<"check"<<mattt.getWidth()<<"x"<<mattt.getHeight()<<std::endl;
		mattt.setWireframe(p_resize,true);
		std::cout<<"check"<<mattt.getWidth()<<"x"<<mattt.getHeight()<<std::endl;
		mattt.draw(0,0,255,255,255,255);
		std::cout<<"check"<<std::endl;
		printToScreen();
		std::cout<<"check"<<std::endl;
		usleep(100);
	}
	finishPrinter();
}
