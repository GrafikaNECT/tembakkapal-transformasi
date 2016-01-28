#include "kapallaut.h"
#include "printchar.h"
#include "bresenham.h"
#include "line-pattern.h"

#include <math.h>

kapallaut::kapallaut(){x=0;y=0;width=0;height=0;turretAngle=0;}

kapallaut::kapallaut(int _x,int _y,float _turretAngle){
	x=_x;
	y=_y;
	turretAngle=_turretAngle;
}

kapallaut::kapallaut(int _x,int _y,int _width,int _height, float _turretAngle){
	x=_x;
	y=_y;
	width=_width;
	height=_height;
	turretAngle=_turretAngle;
}

bullet* kapallaut::shootBullet(){
	bullet * retval = new bullet(x+bulletrelativex,
					x+(getXRes()+getYRes())*cos(turretAngle),
					y+bulletrelativey,
					y+(getXRes()+getYRes())*sin(turretAngle),5);
	return retval;
}

void kapallaut::draw(){
	draw(x,y);
}

void kapallaut::turnTurretRight(){
	turretAngle+=turretTurnSpeed;
}
void kapallaut::turnTurretLeft(){
	turretAngle-=turretTurnSpeed;
}

void kapallaut::draw(int x, int y){
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

void kapallaut::move(int deltax,int deltay){

}
