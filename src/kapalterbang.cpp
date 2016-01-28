#include "kapalterbang.h"
#include "line-pattern.h"
#include "bresenham.h"

kapalterbang::kapalterbang(int _x,int _y){
	x=_x;
	y=_y;
}
kapalterbang::kapalterbang(int _x,int _y,int _width,int _height){
	x=_x;
	y=_y;
	width=_width;
	height=_height;
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
	//nanti harus diganti
	unsigned char g = 255;
	line_pattern p = makeLinePattern(&g,&g,&g,&g,1);
	bresenham_drawline(x,x+width,y,y,p);
	bresenham_drawline(x+width,x+width,y,y+height,p);
	bresenham_drawline(x,x,y,y+height,p);
	bresenham_drawline(x,x,y+height,y+height,p);
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


	//fungsi helper
bool kapalterbang::lineIntersectsSquare(int x1, int y1, int x2, int y2, int xBL, int yBL, int xTR, int yTR){
	bool nointersection = 0;
	nointersection |= (x1 > xTR && x2 > xTR);
	nointersection |= (x1 < xBL && x2 < xBL);
	nointersection |= (y1 > yTR && y2 > yTR);
	nointersection |= (y1 < yBL && y2 < yBL);

	return !nointersection;
}
