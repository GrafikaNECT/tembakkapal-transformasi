#include "game.h"
#include "printchar.h"

#include <unistd.h>
#include <algorithm>

//TODO ini belum selesai!!!

game::game():kapalterbang1(50,getXRes()-10,50,20){
	
}

void game::updateLogic(){
	kapalterbang1.move(-1,0);
	for (int i=0;i<bullets.size();i++){
		
	}
}
void game::drawScreen(){
	drawCanvas(0,0,0,255);
	for (int i=screenObjects.size()-1;i>=0;i--){
		screenObjects[i]->draw();
	}
	printToScreen();
}

void game::init(){
	kapalterbang newkapal(50,getXRes(),50,20);
	kapalterbang1 = newkapal;
	addScreenObject(&kapalterbang1);
	initializePrinter();
}

void game::run(){
	//TODO nanti harus diganti
	init();
	while (true /*nanti diganti*/){
		updateLogic();
		drawScreen();

		usleep(1000);
	}
	finishPrinter();
}

void game::addScreenObject(drawable * newScreenObject){
	screenObjects.push_back(newScreenObject);
	sort(screenObjects.begin(),screenObjects.end());
}
