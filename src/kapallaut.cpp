#include "kapallaut.h"
#include "printchar.h"

#include <math.h>

kapallaut::kapallaut(int _x,int _y){
	x=_x;
	y=_y;
}

kapallaut::kapallaut(int _x,int _y,int _width,int _height){
	x=_x;
	y=_y;
	width=_width;
	height=_height;
}

bullet* kapallaut::shootBullet(int x){
	bullet * retval = new bullet(x+relativebulletx,
					y+relativebullety,
					x+(getXRes()+getYRes())*cos(turretAngle),
					y+(getXRes()+getYRes())*sin(turretAngle),5)
	return retval;
}

void kapallaut::draw(int x, int y){
	drawPicture(x,y,15,200,"ship.txt");
}

void kapallaut::move(int deltax,int deltay){

}
