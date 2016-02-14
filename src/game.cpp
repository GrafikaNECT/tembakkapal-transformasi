#include "game.h"
#include "print.h"

#include <unistd.h>
#include <algorithm>
#include <iostream>

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
	//load alphabet
	ifstream alphabetfile;
	alphabetfile.open("alphabet-2.txt");
	alphabet a1(alphabetfile);
	alphabet2= a1;
	alphabetfile.close();
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

	for (int i=0;i<movingObjects.size();i++){
		movingObjects[i]->oneFrameMove();
	}

	for (int i=0;i<bullets.size();i++){
		bullets[i]->decrementLifetime();
		if (bullets[i]->getLifetime()<=0){
			deletequeue.push(i);
		}
		if (!kapalterbang1.isExploding()
			&& kapalterbang1.hitBullet(*bullets[i])){
			kapalterbang1.explode();
			person * p = new person();
			p -> setX(kapalterbang1.getX());
			p -> setY(kapalterbang1.getY());
			people.push_back(p);
			movingObjects.push_back(p);
			screenObjects.push_back(p);
			//screenObjects.erase(std::find(screenObjects.begin(),screenObjects.end(),&kapalterbang1));
		}
		if (!kapalterbang2.isExploding()
			&& kapalterbang2.hitBullet(*bullets[i])){
			person * p = new person();
			p -> setX(kapalterbang2.getX());
			p -> setY(kapalterbang2.getY());
			people.push_back(p);
			movingObjects.push_back(p);
			screenObjects.push_back(p);
			kapalterbang2.explode();
			//screenObjects.erase(std::find(screenObjects.begin(),screenObjects.end(),&kapalterbang2));
		}	
		if (!kapalterbang3.isExploding()
			&& kapalterbang3.hitBullet(*bullets[i])){
			person * p = new person();
			p -> setX(kapalterbang3.getX());
			p -> setY(kapalterbang3.getY());
			people.push_back(p);
			movingObjects.push_back(p);
			screenObjects.push_back(p);
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
	balingbaling * b;
	initTermios();
	initializePrinter();
	kapalterbang newkapal(getXRes(),getYRes()/2,40,18);
	kapalterbang1 = newkapal;
	kapalterbang1.setMoveSpeedX(1);
	kapalterbang1.setMoveSpeedY(1);
	kapalterbang1.setScaleSpeed(0.01);
	addScreenObject(&kapalterbang1);
	movingObjects.push_back(&kapalterbang1);

	//tempel baling-baling
	b = new balingbaling();
	balingbalings.push_back(b);
	movingObjects.push_back(b);
	addScreenObject(b);
	kapalterbang1.attachkiri(b,10,10);
	b = new balingbaling();
	balingbalings.push_back(b);
	movingObjects.push_back(b);
	addScreenObject(b);
	kapalterbang1.attachkanan(b,40,10);

	kapalterbang newkapal2(getXRes(),getYRes()/2,40,18,"planecolor2.txt");
	kapalterbang2 = newkapal2;
	kapalterbang2.setMoveSpeedX(3);
	kapalterbang2.setMoveSpeedY(1);
	kapalterbang2.setScaleSpeed(0.01);
	addScreenObject(&kapalterbang2);
	movingObjects.push_back(&kapalterbang2);


	//tempel baling-baling
	b = new balingbaling();
	balingbalings.push_back(b);
	movingObjects.push_back(b);
	addScreenObject(b);
	kapalterbang2.attachkiri(b,10,10);
	b = new balingbaling();
	balingbalings.push_back(b);
	movingObjects.push_back(b);
	addScreenObject(b);
	kapalterbang2.attachkanan(b,40,10);

	kapalterbang newkapal3(getXRes(),getYRes()/2,40,18,"planecolor3.txt");
	kapalterbang3 = newkapal3;
	kapalterbang3.setMoveSpeedX(5);
	kapalterbang3.setMoveSpeedY(3);
	kapalterbang3.setScaleSpeed(0.05);
	addScreenObject(&kapalterbang3);
	movingObjects.push_back(&kapalterbang3);

	//tempel baling-baling
	b = new balingbaling();
	balingbalings.push_back(b);
	movingObjects.push_back(b);
	addScreenObject(b);
	kapalterbang3.attachkiri(b,10,10);
	b = new balingbaling();
	balingbalings.push_back(b);
	movingObjects.push_back(b);
	addScreenObject(b);
	kapalterbang3.attachkanan(b,40,10);


	kapallaut newkapallaut(50,getYRes()-80,270*PI/180);
	kapallaut1 = newkapallaut;
	addScreenObject(&kapallaut1);

}

void game::finalize(){
	for (int i=0;i<balingbalings.size();i++){
		delete balingbalings[i];
	}
	for (int i=0;i<people.size();i++){
		delete people[i];
	}
}

bool game::gameOver(){
	return (kapalterbang1.isDead() && kapalterbang2.isDead() && kapalterbang3.isDead());
}

void game::run(){
	//TODO nanti harus diganti
	init();
	drawCanvas(0,0,0,255);
	alphabet2.drawTextCentered("GRAPHICAT",50,3,255,0,0,255);
	alphabet2.drawTextCentered("PLANE SHOOTER",150,3,255,0,0,255);
	alphabet2.drawTextCentered("PRESS A OR D TO MOVE SHIP LEFT OR RIGHT",250,1,255,0,0,255);
	alphabet2.drawTextCentered("PRESS J OR L TO ROTATE THE SHIP TURRET",300,1,255,0,0,255);
	alphabet2.drawTextCentered("PRESS SPACE TO SHOOT",350,1,255,0,0,255);
	alphabet2.drawTextCentered("PRESS Q TO CHANGE WEAPON",400,1,255,0,0,255);
	printToScreen();
	sleep(5);
	while (!gameOver()){
		updateControls();
		updateLogic();
		drawScreen();

		usleep(1000);
	}
	usleep(500);
	alphabet2.drawTextCentered("YOU WIN",300,5,255,0,0,255);
	printToScreen();
	usleep(500);

	finishPrinter();
	resetTermios();
	sleep(2);
	finalize();
}

void game::addScreenObject(drawable * newScreenObject){
	screenObjects.push_back(newScreenObject);
	sort(screenObjects.begin(),screenObjects.end());
}
