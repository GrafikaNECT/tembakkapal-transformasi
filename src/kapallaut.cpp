#include "kapallaut.h"
#include "printchar.h"
#include "bresenham.h"
#include "line-pattern.h"

#include <math.h>

// Ctor kapallaut
kapallaut::kapallaut(){x=0;y=0;width=0;height=0;turretAngle=0;}

// Ctor kapallaut with params
kapallaut::kapallaut(int _x,int _y,float _turretAngle) {
	x=_x;
	y=_y;
	height = 80;
	turretAngle=_turretAngle;
}

// Ctor kapallaut with params
kapallaut::kapallaut(int _x,int _y,int _width,int _height, float _turretAngle) {
	x=_x;
	y=_y;
	width=_width;
	height=_height;
	turretAngle=_turretAngle;
}

// Shoot bullet from kapallaut
bullet* kapallaut::shootBullet() {
	bullet * retval = new bullet(x+bulletrelativex,
					x+(getXRes()+getYRes())*cos(turretAngle),
					y+bulletrelativey,
					y+(getXRes()+getYRes())*sin(turretAngle),5);
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
	bresenham_drawline(x1,x2,y1,y2,cannonptr);
	bresenham_drawline(x1+1,x2+1,y1,y2,cannonptr);
	bresenham_drawline(x1+2,x2+2,y1,y2,cannonptr);
	bresenham_drawline(x1-1,x2-1,y1,y2,cannonptr);
	bresenham_drawline(x1-2,x2-2,y1,y2,cannonptr);
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
