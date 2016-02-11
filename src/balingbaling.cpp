#include "balingbaling.h"
#include "polygon.h"

//bila di-attach, akan diset oleh pesawat
void balingbaling::setX(int _x){x=_x;}
void balingbaling::setY(int _y){y=_y;}
void balingbaling::setScale(float _scale){scale=_scale;}

void balingbaling::setRotateSpeed(float _rotateSpeed){rotateSpeed=_rotateSpeed;}

void balingbaling::draw(){
	//TODO GANTI YANG BENER
	int a = width/2*scale;
	int b = height/2*scale;

	polygon p;
	p.push_back(-a,-b);
	p.push_back(a,-b);
	p.push_back(a,b);
	p.push_back(-a,b);
	polygon protate = p.hasilRotasi(rotateDegree);

	protate.draw(x,y,255,255,0,255,true);
}
void balingbaling::oneFrameMove(){
	rotateDegree=(rotateDegree+rotateSpeed);
	if (rotateDegree>=360)
		rotateDegree-=360;
	if (!attached){
		x+=xSpeed;
		y+=ySpeed;
		ySpeed+=fallaccel;
		rotateSpeed-=36/rotateSpeed;
	}
}

void balingbaling::attach(){
	attached = true;
}
void balingbaling::detach(int _xSpeed, int _ySpeed){
	attached = false;
	xSpeed = _xSpeed;
	ySpeed = _ySpeed;
}
