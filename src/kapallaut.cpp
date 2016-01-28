#include "kapallaut.h"
#include "printchar.h"

#include <math.h>

// Ctor kapallaut
kapallaut::kapallaut(){x=0;y=0;width=0;height=0;turretAngle=0;}

// Ctor kapallaut with params
kapallaut::kapallaut(int _x,int _y,float _turretAngle) {
	x=_x;
	y=_y;
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

// Draw kapallaut on screen
void kapallaut::draw() {
	drawPix(x,y,255,255,255,255);
	draw(x,y);
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

// Draw kapallaut on screen with specific params
void kapallaut::draw(int x, int y) {
	drawPicture(x,y,4,200,"ship.txt","color.txt");
}
