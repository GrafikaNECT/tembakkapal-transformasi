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

game::game():kapalterbang1(50,getXRes()-10,50,20),kapalterbang2(50,getXRes()-5,50,20),kapalterbang3(50,getXRes()-5,50,20){
	
}

void game::updateControls(){
	if (kbhit()){
		char cc = getch();
		switch(cc){
			default:break;
			case 'D':
			case 'd':
				onMoveRightKeyPressed();break;
			case 'A':
			case 'a':
				onMoveLeftKeyPressed();break;
			case 'L':
			case 'l':
				onRightKeyPressed();break;
			case 'J':
			case 'j':
				onLeftKeyPressed();break;
			case 'Q':
			case 'q':
				onSwitchWeaponKeyPressed();break;
			case 32:
				onShootKeyPressed();break;
		}
	}
}

void game::onMoveRightKeyPressed() {
	kapallaut1.moveRight();
}

void game::onMoveLeftKeyPressed() {
	kapallaut1.moveLeft();
}


void game::onRightKeyPressed(){
	kapallaut1.turnTurretRight();
}
void game::onLeftKeyPressed(){
	kapallaut1.turnTurretLeft();

}

void game::onShootKeyPressed(){
	bullet * newbullet = kapallaut1.shootBullet();
	bullets.push_back(newbullet);
	addScreenObject(newbullet);
}

void game::onSwitchWeaponKeyPressed(){
	kapallaut1.switchShootStyle();
}

void game::updateLogic(){
	
	std::queue<int> deletequeue;

	if (!kapalterbang1.isDead()) kapalterbang1.move(-3,0);
	if (!kapalterbang2.isDead()) kapalterbang2.move(-2,0);
	if (!kapalterbang3.isDead()) kapalterbang3.move(-1,0);

	for (int i=0;i<bullets.size();i++){
		bullets[i]->decrementLifetime();
		if (bullets[i]->getLifetime()<=0){
			deletequeue.push(i);
		}
		if (kapalterbang1.hitBullet(*bullets[i])){
			kapalterbang1.explode();
			//screenObjects.erase(std::find(screenObjects.begin(),screenObjects.end(),&kapalterbang1));
		}
		if (kapalterbang2.hitBullet(*bullets[i])){
			kapalterbang2.explode();
			//screenObjects.erase(std::find(screenObjects.begin(),screenObjects.end(),&kapalterbang2));
		}	
		if (kapalterbang3.hitBullet(*bullets[i])){
			kapalterbang3.explode();
			//screenObjects.erase(std::find(screenObjects.begin(),screenObjects.end(),&kapalterbang3));
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
	kapalterbang newkapal2(getXRes(),50,50,20,"planecolor2.txt");
	kapalterbang2 = newkapal2;
	addScreenObject(&kapalterbang2);
	kapalterbang newkapal3(getXRes(),50,50,20,"planecolor3.txt");
	kapalterbang3 = newkapal3;
	addScreenObject(&kapalterbang3);
	kapallaut newkapallaut(50,getYRes()-80,270*PI/180);
	kapallaut1 = newkapallaut;
	addScreenObject(&kapallaut1);

}

bool game::gameOver(){
	return (kapalterbang1.isDead() && kapalterbang2.isDead() && kapalterbang3.isDead());
}

void game::run(){
	//TODO nanti harus diganti
	init();
	drawCanvas(0,0,0,255);
	drawTextCentered("GRAPHICAT",9,50,3,255,0,0,255);
	drawTextCentered("PLANE SHOOTER",13,150,3,255,0,0,255);
	drawTextCentered("Press A or D to move ship left or right",39,250,1,255,0,0,255);
	drawTextCentered("Press J or L to rotate the ship turret",38,300,1,255,0,0,255);
	drawTextCentered("Press Space to shoot",20,350,1,255,0,0,255);
	drawTextCentered("Press Q to change weapon",24,400,1,255,0,0,255);
	printToScreen();
	sleep(5);
	while (!gameOver()){
		updateControls();
		updateLogic();
		drawScreen();

		usleep(200);
	}
	usleep(500);
	drawTextCentered("YOU WIN",7,300,5,255,0,0,255);
	printToScreen();
	usleep(500);

	finishPrinter();
	resetTermios();
	sleep(2);
}

void game::addScreenObject(drawable * newScreenObject){
	screenObjects.push_back(newScreenObject);
	sort(screenObjects.begin(),screenObjects.end());
}
