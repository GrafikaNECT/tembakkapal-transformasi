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

	// Satu baling-baling atas
	t0x = 0; t0y = 0;
	t1x = width/12 * scale;
	t1y = height/10 * scale;
	t2x = width/6 * scale;
	t2y = 3 * height/10 * scale;
	t3x = width/12 * scale;
	t3y = 4 * height/10 * scale;
	t4x = 0;
	t4y = height/2 * scale;

	polygon p1;
	p1.push_back(t0x, t0y);
	p1.push_back(t1x, t1y);
	p1.push_back(t2x, t2y);
	p1.push_back(t3x, t3y);
	p1.push_back(t4x, t4y);
	p1.push_back(-t3x, t3y);
	p1.push_back(-t2x, t2y);
	p1.push_back(-t1x, t1y);
	polygon protate1 = p1.hasilRotasi(rotateDegree);

	protate1.draw(x,y,255,255,0,255,true);
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
