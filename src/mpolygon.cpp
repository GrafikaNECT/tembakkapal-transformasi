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

	//test print
	std::cout<<"hasil putar: "<<std::endl;
	polygon pPutar = p.hasilRotasi(180);
	for (int i=0;i<pPutar.size();i++){
		std::cout<<pPutar[i].getX()<<"\t"<<pPutar[i].getY()<<std::endl;
	}
	std::cout<<"\n"<<std::endl;

	polygon pGeser = p.hasilGeser(100,100);
	for (int i=0;i<pPutar.size();i++){
		std::cout<<pGeser[i].getX()<<"\t"<<pGeser[i].getY()<<std::endl;
	}
	std::cout<<"\n"<<std::endl;

	drawCanvas(0,0,0,255);
	p.draw(10,10,255,255,255,255,true);
	printToScreen();
	sleep(3);
	p.draw(10,10,255,255,255,255,true);	
	printToScreen();
	sleep(3);

	for (float f = 0; f < 360; f+=1){
		drawCanvas(0,0,0,255);
		p.hasilRotasi(f).draw(10,10,255,255,255,255,true);
		printToScreen();
		usleep(100);
	}
	point poros(50,50);
	for (float f = 0; f < 360; f+=1){
		
		drawCanvas(0,0,0,255);
		p.hasilRotasi(f,poros).draw(10,10,255,255,255,255,true);
		printToScreen();
		usleep(100);
	}

	finishPrinter();
}
