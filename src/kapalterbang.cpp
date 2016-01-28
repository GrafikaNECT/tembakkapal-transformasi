#include "kapalterbang.h"
#include "line-pattern.h"
#include "bresenham.h"
#include "printchar.h"

kapalterbang::kapalterbang(int _x,int _y){
	x=_x;
	y=_y;
	exploding=false;
}
kapalterbang::kapalterbang(int _x,int _y,int _width,int _height){
	x=_x;
	y=_y;
	width=_width;
	height=_height;
	exploding=false;
}
bool kapalterbang::hitBullet(bullet b){
	return lineIntersectsSquare(
		b.getX1(),
		b.getY1(),
		b.getX2(),
		b.getY2(),
		x,y,x+width,y+width);
}

#include <iostream>
void kapalterbang::draw(){
	//TODO nanti harus diganti
	unsigned char g = 255;
	std::cout << x << " " << y << std::endl;
	line_pattern p = makeLinePattern(&g,&g,&g,&g,1);
	bresenham_drawline(x,x+width,y,y,p);
	bresenham_drawline(x+width,x+width,y,y+height,p);
	bresenham_drawline(x,x,y,y+height,p);
	bresenham_drawline(x,x,y+height,y+height,p);
	if (isExploding())drawText("BOOM",4,getX(),getY(),2,255,0,0,255);
	
}
void kapalterbang::move(int deltax,int deltay){
	x+=deltax;
	y+=deltay;
}

int kapalterbang::getX(){
	return x;
}

int kapalterbang::getY(){
	return y;
}

int kapalterbang::getWidth(){
	return width;
}

int kapalterbang::getHeight(){
	return height;
}

bool kapalterbang::isExploding(){
	return exploding;
}

void kapalterbang::setExploding(bool b){
	exploding=b;
}

void kapalterbang::explode(){
	setExploding(true);
}


	//fungsi helper
bool kapalterbang::lineIntersectsSquare(int x1, int y1, int x2, int y2, int xBL, int yBL, int xTR, int yTR){

	bool nointersection = 0;
	nointersection |= (_x1 > xTR && _x2 > xTR);
	nointersection |= (_x1 < xBL && _x2 < xBL);
	nointersection |= (_y1 > yTR && _y2 > yTR);
	nointersection |= (_y1 < yBL && _y2 < yBL);

	return !nointersection;
}
