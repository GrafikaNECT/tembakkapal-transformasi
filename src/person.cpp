#include "person.h"
#include "print.h"
#include <cmath>
#include <chrono>

static std::default_random_engine person::rd(std::chrono::system_clock::now().time_since_epoch().count());
std::normal_distribution<double> person::rotateDegreeRandomGenerator(0.0,10.0);

person::person():xSpeed(0),ySpeed(0),rotateDegreeSpeed(0){
	rotateDegree = rotateDegreeRandomGenerator(rd);
}

void person::oneFrameMove(){
	changeMiring();

	//terkait kecepatan
	gravity_accelerate();
	drag();

	move();
}
#include <iostream>
void person::draw(){
	//TODO GANTI JADI BUKAN KOTAK
	polygon p;
	p.push_back(-30,-20);
	p.push_back(30,-20);
	p.push_back(30,80);
	p.push_back(-30,80);

	polygon protate = p.hasilRotasi(rotateDegree);
	protate.draw(x,y,0,255,255,255,true);
}

void person::gravity_accelerate(){
	ySpeed+=gravity_accel;
}

void person::drag(){
	if (ySpeed>maxYSpeed*cos(rotateDegree)) ySpeed = maxYSpeed;
	xSpeed-=miring_xnambah_coeff*ySpeed*sin(rotateDegree);
}

void person::changeMiring(){
	rotateDegreeAccel=-osc_coeff*sin(rotateDegree)-osc_damp_coeff*rotateDegreeSpeed;
	rotateDegreeSpeed+=rotateDegreeAccel;
	rotateDegree+=rotateDegreeSpeed;

	//pengaman
	if (rotateDegree>maxDegree){
		 rotateDegree=maxDegree;
		rotateDegreeAccel=0;
		rotateDegreeSpeed=0;
	}
	if (rotateDegree<-maxDegree){
		 rotateDegree=-maxDegree;
		rotateDegreeAccel=0;
		rotateDegreeSpeed=0;
	}
}

void person::move(){
	x+=xSpeed;
	y+=ySpeed;
}
