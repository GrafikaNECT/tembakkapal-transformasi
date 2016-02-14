#include "person.h"
#include "print.h"
#include <cmath>
#include <chrono>

static std::default_random_engine person::rd(std::chrono::system_clock::now().time_since_epoch().count());
std::normal_distribution<double> person::rotateDegreeRandomGenerator(0.0,10.0);

person::person():xSpeed(0),ySpeed(0),rotateDegreeSpeed(0){
	rotateDegree = rotateDegreeRandomGenerator(rd);
	initShape();
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
	polygon bodyrotate = body.hasilRotasi(rotateDegree);
	bodyrotate.draw(x,y,245,214,164,255,false);
	polygon shirtrotate = shirt.hasilRotasi(rotateDegree);
	shirtrotate.draw(x,y,255,0,0,255,false);
	//polygon pantsrotate = pants.hasilRotasi(rotateDegree);
	//pantsrotate.draw(x,y,0,0,255,255,false);
}

void person::gravity_accelerate(){
	ySpeed+=gravity_accel;
}

void person::drag(){
	if (ySpeed>maxYSpeed*cos(rotateDegree)) ySpeed = maxYSpeed;
	if (xSpeed>maxXSpeed) xSpeed = maxXSpeed;
	if (xSpeed < -maxXSpeed) xSpeed = -maxXSpeed;
	xSpeed+=miring_xnambah_coeff*ySpeed*sin(rotateDegree);
}

void person::changeMiring(){
	rotateDegree+=rotateDegreeSpeed;
	rotateDegreeSpeed+=rotateDegreeAccel;
	rotateDegreeAccel=-osc_coeff*sin(rotateDegree)-osc_damp_coeff*rotateDegreeSpeed;

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

void person::initShape() {

	body.push_back(15,19);
	body.push_back(16,19);
	body.push_back(21,21);
	body.push_back(31,21);
	body.push_back(35,19);
	body.push_back(36,19);
	body.push_back(38,20);
	body.push_back(37,21);
	body.push_back(35,23);
	body.push_back(32,24);
	body.push_back(32,34);
	body.push_back(34,36);
	body.push_back(33,37);
	body.push_back(30,37);
	body.push_back(29,36);
	body.push_back(28,34);
	body.push_back(27,30);
	body.push_back(26,30);
	body.push_back(25,34);
	body.push_back(24,36);
	body.push_back(23,37);
	body.push_back(20,37);
	body.push_back(19,36);
	body.push_back(21,34);
	body.push_back(21,24);
	body.push_back(18,23);
	body.push_back(16,21);
	body.push_back(14,20);

	shirt.push_back(20,20);
	shirt.push_back(17,23);
	shirt.push_back(20,24);
	shirt.push_back(20,30);
	shirt.push_back(33,30);
	shirt.push_back(33,24);
	shirt.push_back(35,23);
	shirt.push_back(33,20);
	

	pants.push_back(21,30);
	pants.push_back(20,35);
	pants.push_back(25,35);
	pants.push_back(26,33);
	pants.push_back(27,33);
	pants.push_back(28,35);
	pants.push_back(3,23);
	pants.push_back(3,35);
	pants.push_back(32,30);

}
