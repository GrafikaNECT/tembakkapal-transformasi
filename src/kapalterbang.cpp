#include "kapalterbang.h"
#include "line-pattern.h"
#include "bresenham.h"
#include "print.h"
#include "drawBitPicture-old.h"
#include "polygon.h"
#include <cmath>

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
			/*p.push_back(0,0);
			p.push_back(width,0);
			p.push_back(width,height);
			p.push_back(0,height);*/

			p.push_back(19,0);
			p.push_back(19,5);
			p.push_back(18,6);
			p.push_back(10,6);
			p.push_back(17,7);
			p.push_back(16,9);
			p.push_back(15,10);
			p.push_back(14,11);
			p.push_back(0,11);
			p.push_back(14,13);
			p.push_back(15,14);
			p.push_back(17,15);
			p.push_back(19,16);
			p.push_back(20,16);
			p.push_back(22,15);
			p.push_back(24,14);
			p.push_back(25,13);
			p.push_back(39,11);
			p.push_back(25,11);
			p.push_back(24,10);
			p.push_back(23,9);
			p.push_back(22,7);
			p.push_back(29,6);
			p.push_back(21,6);
			p.push_back(20,5);
			p.push_back(20,0);

			polygon window;
			window.push_back(18,9);
			window.push_back(16,10);
			window.push_back(23,10);
			window.push_back(21,9);
			polygon pdraw = p.hasilSkala(scale,scale);
			polygon windraw = window.hasilSkala(scale,scale);
			pdraw.draw(x,y,255,255,255,255,false);
			windraw.draw(x,y,0,0,0,255,false);


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
		
		//gerakin baling-baling
		if (balingbalingkiriAttached){
			balingbalingkiri->setX(getX()+balingbalingkiriX*scale);
			balingbalingkiri->setY(getY()+balingbalingkiriY*scale);
			balingbalingkiri->setScale(scale);
			balingbalingkiri -> setRotateSpeed((getMoveSpeedX()+getMoveSpeedY()+getScaleSpeed())*5);
		}
		if (balingbalingkananAttached){
			balingbalingkanan->setX(getX()+balingbalingkananX*scale);
			balingbalingkanan->setY(getY()+balingbalingkananY*scale);
			balingbalingkanan->setScale(scale);
			balingbalingkanan -> setRotateSpeed((getMoveSpeedX()+getMoveSpeedY()+getScaleSpeed())*5);
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
		detachkiri();
		detachkanan();
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

void kapalterbang::attachkiri(balingbaling * b, int relativex, int relativey){
	b->attach();
	balingbalingkiri = b;
	balingbalingkiriX=relativex;
	balingbalingkiriY=relativey;
	balingbalingkiriAttached = true;
}
void kapalterbang::attachkanan(balingbaling * b, int relativex, int relativey){
	b->attach();
	balingbalingkanan = b;
	balingbalingkananX=relativex;
	balingbalingkananY=relativey;
	balingbalingkananAttached = true;
}

void kapalterbang::detachkiri(){
	balingbalingkiri->detach(-getMoveSpeedX(),-getMoveSpeedY());
	balingbalingkiriAttached = false;
}
void kapalterbang::detachkanan(){
	balingbalingkanan->detach(-getMoveSpeedX(),-getMoveSpeedY());
	balingbalingkananAttached = false;
}
