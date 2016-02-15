#include "banterbakar.h"
#include "polygon.h"
#include "print.h"

#include <chrono>

//bila di-attach, akan diset oleh pesawat
void banterbakar::setX(int _x){x=_x;}
void banterbakar::setY(int _y){y=_y;}

banterbakar::banterbakar(int _x, int _y, int baseXSpeed, int baseYSpeed){
	x=_x;
	y=_y;
	xSpeed=baseXSpeed+speedRandomGenerator(rd);
	ySpeed=baseYSpeed+speedRandomGenerator(rd);
}

void banterbakar::draw(){
	//TODO GANTI YANG BENER
	int a = width;
	int b = height;

	polygon p;
	p.push_back(0,0);
	p.push_back(a,0);
	p.push_back(a,b);
	p.push_back(0,b);

	p.draw(x,y,0,0,0,255,true);

}
void banterbakar::oneFrameMove(){
	x+=xSpeed;
	y+=ySpeed;
	ySpeed+=fallaccel;
	if (y>getYRes()-100 && ySpeed>0){
		ySpeed=-ySpeed*bounceelasticity;
	}
}

static std::default_random_engine banterbakar::rd(std::chrono::system_clock::now().time_since_epoch().count());
static std::normal_distribution<double> banterbakar::speedRandomGenerator(0,5);
