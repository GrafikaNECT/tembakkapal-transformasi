#include "kapalterbang.h"
#include "line-pattern.h"
#include "bresenham.h"
#include "printchar.h"

kapalterbang::kapalterbang(int _x,int _y){
	x=_x;
	y=_y;
	width = 18*3;
	height = 6*3;
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
	drawPicture(x,y,3,200,"plane2.txt","color.txt");
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

char* kapalterbang::getColorFileName(){
	return colorFileName;
}

void kapalterbang::setColorFileName(char* file){
	colorFileName = file;
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
//line bukan segment
	int y = (float)(y2-y1)/(float)(x2-x1)*xTR+y1;
	if (y>=yBL && y<=yTR) return true;
 	y = (float)(y2-y1)/(float)(x2-x1)*xBL+y1;
	if (y>=yBL && y<=yTR) return true;
	int x = (float)(x2-x1)/(float)(y2-y1)*yTR+x1;
	if (x>=xBL && x<=xTR) return true;
 	x = (float)(x2-x1)/(float)(y2-y1)*yBL+x1;
	if (x>=xBL && x<=xTR) return true;
	return false;
}
