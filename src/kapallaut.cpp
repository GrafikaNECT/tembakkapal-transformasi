#include "kapallaut.h"
#include "printchar.h"

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
	drawPix(x,y,255,255,255,255);
	draw(x,y);
}

void kapallaut::turnTurretRight(){
	//TODO belum
}
void kapallaut::turnTurretLeft(){
	//TODO belum
}


void kapallaut::draw(int x, int y){
	drawPicture(x,y,4,200,"ship.txt","color.txt");
}

void kapallaut::move(int deltax,int deltay){

}
