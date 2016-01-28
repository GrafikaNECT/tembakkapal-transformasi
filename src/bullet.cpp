#include "bullet.h"
#include "bresenham.h"

bullet::bullet(int _x1,int _x2,int _y1,int _y2, int _lifetime){
	x1=_x1;
	x2=_x2;
	y1=_y1;
	y2=_y2;
	lifetime=_lifetime;
	style = defaultStyle(140);
}
void bullet::draw(){
	bresenham_drawline(x1,x2,y1,y2,style);
}

int bullet::getX1(){
	return x1;
}
int bullet::getY1(){
	return y1;

}
int bullet::getY2(){
	return y2;

}
int bullet::getX2(){
	return x2;
}

int bullet::getLifetime(){
	return lifetime;
}
void bullet::decrementLifetime(){
	lifetime--;
}

line_pattern bullet::defaultStyle(unsigned char gr){
	unsigned char a = 255;
	return makeLinePattern(&gr,&gr,&gr,&a,1);
}
