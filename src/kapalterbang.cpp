#include "kapalterbang.h"
#include "line-pattern.h"
#include "bresenham.h"
#include "printchar.h"

kapalterbang::kapalterbang(int _x,int _y){
	x=_x;
	y=_y;
	exploding=false;
	draw();
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

void kapalterbang::draw(){
	//TODO nanti harus diganti
	drawPicture(0,0,15,200,"plane2.txt","color.txt");
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

	//TODO benerin ini ntar

	bool nointersection = 0;
	nointersection |= (x1 > xTR && x2 > xTR);
	nointersection |= (x1 < xBL && x2 < xBL);
	nointersection |= (y1 > yTR && y2 > yTR);
	nointersection |= (y1 < yBL && y2 < yBL);

	return !nointersection;
}
