#include "game.h"
#include "printchar.h"

#include <unistd.h>
#include <algorithm>

#include <queue>



#include <stdlib.h> 
#include <unistd.h> 
#include <sys/select.h> 
#include <termios.h> 
#include <time.h> 
#include <stdio.h>

static struct termios old_termios, new_termios;
/* restore new terminal i/o settings */
void resetTermios(){
	tcsetattr(0,TCSANOW,&old_termios);
}
/* initialize new terminal i/o settings */
void initTermios(){
	tcgetattr(0,&old_termios); // store old terminal 
	new_termios = old_termios; // assign to new setting 
	new_termios.c_lflag &= ~ICANON; // disable buffer i/o 
	new_termios.c_lflag &= ~ECHO; // disable echo mode 
	tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting 
}
/* detect keyboard press */
int kbhit(){
	struct timeval tv = {0L,0L};
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0,&fds);
	return select(1,&fds,NULL,NULL,&tv);
}
/* read 1 character */
char getch(){
	char ch;
	ch = getchar();
	return ch;
}

//TODO ini belum selesai!!!

game::game():kapalterbang1(50,getXRes()-10,50,20){
	
}

void game::updateControls(){
	if (kbhit()){
		char cc = getch();
		resetTermios();
		switch(cc){
			default:break;
			case 'D':
			case 'd':
				onRightKeyPressed();break;
			case 'A':
			case 'a':
				onLeftKeyPressed();break;
			case 'S':
			case 's':
				onShootKeyPressed();break;
		}
	}
}


void game::onRightKeyPressed(){
	kapallaut1.turnTurretRight();
}
void game::onLeftKeyPressed(){
	kapallaut1.turnTurretLeft();

}

#include <iostream>
void game::onShootKeyPressed(){
	bullet * newbullet = kapallaut1.shootBullet();

	std::cout<< newbullet->getX1() <<std::endl;
	std::cout<< newbullet->getY1() <<std::endl;
	std::cout<< newbullet->getX2() <<std::endl;
	std::cout<< newbullet->getY2() <<std::endl;

	bullets.push_back(newbullet);
	addScreenObject(newbullet);
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

	initTermios();
	initializePrinter();
	kapalterbang newkapal(getXRes(),50,50,20);
	kapalterbang1 = newkapal;
	addScreenObject(&kapalterbang1);
	kapallaut newkapallaut(50,getYRes()-50,270*PI/180);
	kapallaut1 = newkapallaut;
	addScreenObject(&kapallaut1);

}

bool game::gameOver(){
	return kapalterbang1.isExploding() || kapalterbang1.getX()<0;
}

void game::run(){
	//TODO nanti harus diganti
	init();
	while (!gameOver()){
		updateControls();
		updateLogic();
		drawScreen();

		usleep(200);
	}
	finishPrinter();
	resetTermios();
}

void game::addScreenObject(drawable * newScreenObject){
	screenObjects.push_back(newScreenObject);
	sort(screenObjects.begin(),screenObjects.end());
}
