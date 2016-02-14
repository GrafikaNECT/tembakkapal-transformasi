#include "balingbaling.h"
#include "polygon.h"

#include <chrono>

//bila di-attach, akan diset oleh pesawat
void balingbaling::setX(int _x){x=_x;}
void balingbaling::setY(int _y){y=_y;}
void balingbaling::setScale(float _scale){scale=_scale;}

void balingbaling::setRotateSpeed(float _rotateSpeed){rotateSpeed=_rotateSpeed;}

void balingbaling::draw(){
	//TODO GANTI YANG BENER
	// int a = width/2*scale;
	// int b = height/2*scale;

	// polygon p;
	// p.push_back(-a,-b);
	// p.push_back(a,-b);
	// p.push_back(a,b);
	// p.push_back(-a,b);
	// polygon protate = p.hasilRotasi(rotateDegree);

	// protate.draw(x,y,255,255,0,255,true);

	// Satu baling-baling atas
	int t0x = 0; int t0y = 0;
	int t1x = width/12 * scale;
	int t1y = height/10 * scale;
	int t2x = width/6 * scale;
	int t2y = 3 * height/10 * scale;
	int t3x = 2 * width/12 * scale;
	int t3y = 4 * height/10 * scale;
	int t4x = 0;
	int t4y = height/2 * scale;

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

	protate1.draw(x,y,255,255,0,255);


	// Satu baling-baling kanan

	polygon p2;
	p2.push_back(t0x, t0y);
	p2.push_back(t1y, t1x);
	p2.push_back(t2y, t2x);
	p2.push_back(t3y, t3x);
	p2.push_back(t4y, t4x);
	p2.push_back(t3y, -t3x);
	p2.push_back(t2y, -t2x);
	p2.push_back(t1y, -t1x);
	polygon protate2 = p2.hasilRotasi(rotateDegree);

	protate2.draw(x,y,255,255,0,255);


	// Satu baling-baling bawah

	polygon p3;
	p3.push_back(t0x, t0y);
	p3.push_back(t1x, -t1y);
	p3.push_back(t2x, -t2y);
	p3.push_back(t3x, -t3y);
	p3.push_back(t4x, -t4y);
	p3.push_back(-t3x, -t3y);
	p3.push_back(-t2x, -t2y);
	p3.push_back(-t1x, -t1y);
	polygon protate3 = p3.hasilRotasi(rotateDegree);

	protate3.draw(x,y,255,255,0,255);


	// Satu baling-baling kiri

	polygon p4;
	p4.push_back(t0x, t0y);
	p4.push_back(-t1y, t1x);
	p4.push_back(-t2y, t2x);
	p4.push_back(-t3y, t3x);
	p4.push_back(-t4y, t4x);
	p4.push_back(-t3y, -t3x);
	p4.push_back(-t2y, -t2x);
	p4.push_back(-t1y, -t1x);
	polygon protate4 = p4.hasilRotasi(rotateDegree);

	protate4.draw(x,y,255,255,0,255);
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
	xSpeed = _xSpeed+speedRandomGenerator(rd)/3;
	ySpeed = _ySpeed+speedRandomGenerator(rd)/3;
	rotateSpeed += speedRandomGenerator(rd);
}

static std::default_random_engine balingbaling::rd(std::chrono::system_clock::now().time_since_epoch().count());
static std::normal_distribution<double> balingbaling::speedRandomGenerator(0,5);
