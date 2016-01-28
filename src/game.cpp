#include "game.h"
#include "printchar.h"

#include <unistd.h>
#include <algorithm>

#include <queue>

//TODO ini belum selesai!!!

game::game():kapalterbang1(50,getXRes()-10,50,20){
	
}

void game::updateLogic(){
	
	std::queue<int> deletequeue;

	kapalterbang1.move(-1,0);
	for (int i=0;i<bullets.size();i++){
		bullets[i]->decrementLifetime();
		if (bullets[i]->getLifetime()<=0){
			deletequeue.push(i);
		}
		if (kapalterbang1.hitBullet(*bullets[i])){
			kapalterbang1.explode();
		}
	}

	//menghapus dari bullets
	int numdel = 0;
	int i;
	while (!deletequeue.empty()){
		i=deletequeue.front();
		deletequeue.pop();
		delete bullets[i];
		screenObjects.erase(std::remove(screenObjects.begin(),screenObjects.end(),bullets[i]),screenObjects.end());
		bullets.erase(bullets.begin()+i-numdel);
		numdel++;
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
	initializePrinter();
	kapalterbang newkapal(getXRes(),50,50,20);
	kapalterbang1 = newkapal;
	addScreenObject(&kapalterbang1);

	//untuk TESTING
	bullet* b = new bullet(0,2*getXRes()/3,getYRes()/2,0,4);
	bullets.push_back(b);
	addScreenObject(bullets[bullets.size()-1]);
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
