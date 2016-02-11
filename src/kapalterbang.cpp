#include "kapalterbang.h"
#include "line-pattern.h"
#include "bresenham.h"
#include "print.h"
#include "drawBitPicture-old.h"
#include "polygon.h"

kapalterbang::kapalterbang(int _x,int _y){
	startX=_x;
	startY=_y;
	x=_x;
	y=_y;
	width = 18*3;
	height = 6*3;
	exploding=false;
	//dead=false;
	setColorFileName("planecolor1.txt");
	draw();
}

kapalterbang::kapalterbang(int _x,int _y,char* colorfile){
	startX=_x;
	startY=_y;
	x=_x;
	y=_y;
	width = 18*3;
	height = 6*3;
	exploding=false;
	//dead=false;
	setColorFileName(colorfile);
	draw();
}

kapalterbang::kapalterbang(int _x,int _y,int _width,int _height){
	startX=_x;
	startY=_y;
	x=_x;
	y=_y;
	width=_width;
	height=_height;
	exploding=false;
	//dead=false;
	setColorFileName("planecolor1.txt");
}

kapalterbang::kapalterbang(int _x,int _y,int _width,int _height,char* colorfile){
	startX=_x;
	startY=_y;
	x=_x;
	y=_y;
	width=_width;
	height=_height;
	exploding=false;
	//dead=false;
	setColorFileName(colorfile);
}


bool kapalterbang::hitBullet(bullet b){
	return lineIntersectsSquare(
		b.getX1(),
		b.getY1(),
		b.getX2(),
		b.getY2(),
		x,y,x+width*scale,y+height*scale);
}

void kapalterbang::draw(){
	//TODO nanti harus diganti
	if (!isDead()) {
		if (isExploding()) {
			drawPicture(getX(),getY(),3,200,"explosion.txt","explosioncolor.txt");
			deadlifetime--;
		} else {
			//drawPicture(x,y,3,200,"plane2.txt",colorFileName);
			//ini kotak dummy
			polygon p;
			p.push_back(0,0);
			p.push_back(width,0);
			p.push_back(width,height);
			p.push_back(0,height);

			polygon pdraw = p.hasilSkala(scale,scale);
			pdraw.draw(x,y,255,255,255,255,true);
		}
	}
		//drawText("BOOM",4,getX(),getY(),2,255,0,0,255);
	
}

void kapalterbang::move(int deltax,int deltay){
	x+=deltax;
	y+=deltay;
}

void kapalterbang::oneFrameMove(){
	if (!isDead()){
		move(-getMoveSpeedX(),-getMoveSpeedY());
		scale+=scaleSpeed;
		if (x<-width*scale||y<-height*scale){
			x=startX;
			y=startY;
			scale=0;
		}

	}
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

bool kapalterbang::isDead() {
	return (deadlifetime==0);
}

void kapalterbang::explode(){
	if (!isDead()) {
		setExploding(true);
		deadlifetime=3;
	}
}

	//fungsi helper
bool kapalterbang::lineIntersectsSquare(int x1, int y1, int x2, int y2, int xBL, int yBL, int xTR, int yTR){

	for (int x=xBL;x<=xTR;x++){
		long y = ((long)x-(long)x1)*((long)y2-(long)y1)/((long)x2-(long)x1)+y1;
		if (y>=yBL && y<= yTR) return true;
		drawPix(x-1,y-1,255,255,255,255);
	}
	return false;

}

void kapalterbang::setMoveSpeedY(int v){
	moveSpeedY=v;
}
int kapalterbang::getMoveSpeedY(){
	return moveSpeedY;
}

void kapalterbang::setMoveSpeedX(int v){
	moveSpeedX=v;
}
int kapalterbang::getMoveSpeedX(){
	return moveSpeedX;
}

void kapalterbang::setScaleSpeed(float v){
	scaleSpeed = v;
}

float kapalterbang::getScaleSpeed(){
	return scaleSpeed;
}
