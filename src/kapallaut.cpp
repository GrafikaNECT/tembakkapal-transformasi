#include "kapallaut.h"
#include "printchar.h"
#include "bresenham.h"
#include "line-pattern.h"

#include <math.h>

static std::vector<line_pattern> kapallaut::initShootStyles(){
	std::vector<line_pattern> retval;

	unsigned char full = 255;
	unsigned char empty = 0;
	retval.push_back(makeLinePattern(&empty,&empty,&full,&full,1));

	
	unsigned char AR [] = {255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	unsigned char AG [] = {0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0};
	unsigned char AB []= {0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0};
	unsigned char AAlpha []= {255, 255, 255, 255, 0, 255, 255, 255, 255, 0, 255, 255, 255, 255, 0};
	line_pattern patternA = makeLinePattern(AR,AG,AB,AAlpha , 15);
	retval.push_back(patternA);

	return retval;
}

static const std::vector<line_pattern> kapallaut::shootStyles = kapallaut::initShootStyles();

// Ctor kapallaut
kapallaut::kapallaut(){x=0;y=0;width=0;height=0;turretAngle=0;}

// Ctor kapallaut with params
kapallaut::kapallaut(int _x,int _y,float _turretAngle) {
	x=_x;
	y=_y;
	height = 80;
	turretAngle=_turretAngle;
	shootStyleNum = 0;
}

// Ctor kapallaut with params
kapallaut::kapallaut(int _x,int _y,int _width,int _height, float _turretAngle) {
	x=_x;
	y=_y;
	width=_width;
	height=_height;
	turretAngle=_turretAngle;
	shootStyleNum = 0;
}

// Shoot bullet from kapallaut
bullet* kapallaut::shootBullet() {
	bullet * retval = new bullet(x+bulletrelativex,
					x+(getXRes()+getYRes())*cos(turretAngle),
					y+bulletrelativey,
					y+(getXRes()+getYRes())*sin(turretAngle),5,shootStyles[shootStyleNum]);
	return retval;
}


void kapallaut::draw(){
	drawPicture(x,y,4,200,"ship.txt","color.txt");
	drawTurret();
}

void kapallaut::drawTurret(){

	static const char gg[] = {150,140};
	static const char alph[] = {255,255};
	static const line_pattern cannonptr = makeLinePattern(gg,gg,gg,alph,2);

	int x1 = x+bulletrelativex;
	int length = 20;
	int x2 = x1+length*cos(turretAngle);
	int y1 = y + bulletrelativey;
	int y2 = y1 +length*sin(turretAngle);
	bresenham_drawline(x1,x2,y1,y2,shootStyles[shootStyleNum]);
	bresenham_drawline(x1+1,x2+1,y1,y2,shootStyles[shootStyleNum]);
	bresenham_drawline(x1+2,x2+2,y1,y2,shootStyles[shootStyleNum]);
	bresenham_drawline(x1-1,x2-1,y1,y2,shootStyles[shootStyleNum]);
	bresenham_drawline(x1-2,x2-2,y1,y2,shootStyles[shootStyleNum]);
}

// Move the ship to right
void kapallaut::moveRight() {
	x+=shipSpeed;
}

// Move the ship to left
void kapallaut::moveLeft() {
	x-=shipSpeed;
}

// Turn shoot degree to right
void kapallaut::turnTurretRight() {
	if (turretAngle < (2*PI)-(PI/30))
		turretAngle+=turretTurnSpeed;

}

// Turn shoot degree to left
void kapallaut::turnTurretLeft() {
	if (turretAngle > (PI)+(PI/30))
		turretAngle-=turretTurnSpeed;
}

int kapallaut::getHeight(){
	return height;
}

void kapallaut::switchShootStyle(){
	shootStyleNum++;
	if (shootStyleNum>=shootStyles.size())shootStyleNum=0;
}
