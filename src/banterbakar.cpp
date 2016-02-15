#include "banterbakar.h"
#include "polygon.h"

#include <chrono>

//bila di-attach, akan diset oleh pesawat
void banterbakar::setX(int _x){x=_x;}
void banterbakar::setY(int _y){y=_y;}

void banterbakar::draw(){
	//TODO GANTI YANG BENER
	int a = width;
	int b = height;

	polygon p;
	p.push_back(-a,-b);
	p.push_back(a,-b);
	p.push_back(a,b);
	p.push_back(-a,b);

	p.draw(x,y,0,0,0,255,true);

}
void banterbakar::oneFrameMove(){
	x+=xSpeed;
	y+=ySpeed;
	ySpeed+=fallaccel;
	if (
}

void banterbakar::attach(){
	attached = true;
}
void banterbakar::detach(int _xSpeed, int _ySpeed){
	attached = false;
	xSpeed = _xSpeed+speedRandomGenerator(rd)/3;
	ySpeed = _ySpeed+speedRandomGenerator(rd)/3;
	rotateSpeed += speedRandomGenerator(rd);
}

static std::default_random_engine banterbakar::rd(std::chrono::system_clock::now().time_since_epoch().count());
static std::normal_distribution<double> banterbakar::speedRandomGenerator(0,5);
