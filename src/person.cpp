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
	polygon pantsrotate = pants.hasilRotasi(rotateDegree);
	pantsrotate.draw(x,y,128,0,128,255,false);
	polygon parachutePart1 = parachute1.hasilRotasi(rotateDegree);
	parachutePart1.draw(x,y,229,20,60,255,false);
	polygon parachutePart2 = parachute2.hasilRotasi(rotateDegree);
	parachutePart2.draw(x,y,255,0,0,255,false);
	polygon parachutePart3 = parachute3.hasilRotasi(rotateDegree);
	parachutePart3.draw(x,y,255,99,71,255,false);
	polygon parachutePart4 = parachute4.hasilRotasi(rotateDegree);
	parachutePart4.draw(x,y,255,127,80,255,false);
	polygon parachutePart5 = parachute5.hasilRotasi(rotateDegree);
	parachutePart5.draw(x,y,205,92,92,255,false);
	polygon parachutelinerotate1 = parachuteline1.hasilRotasi(rotateDegree);
	parachutelinerotate1.draw(x,y,205,92,92,255,false);
	polygon parachutelinerotate2 = parachuteline2.hasilRotasi(rotateDegree);
	parachutelinerotate2.draw(x,y,205,92,92,255,false);
	polygon headrotate = head.hasilRotasi(rotateDegree);
	headrotate.draw(x,y,245,214,164,255,false);
	polygon hairrotate = hair.hasilRotasi(rotateDegree);
	hairrotate.draw(x,y,0,0,0,255,false);


}

void person::gravity_accelerate(){
	ySpeed+=gravity_accel;
}

void person::drag(){
	if (ySpeed > maxYSpeed*cos(rotateDegree)) ySpeed = maxYSpeed;
	if (xSpeed > maxXSpeed) xSpeed = maxXSpeed;
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

	body.push_back(15,33);
	body.push_back(16,33);
	body.push_back(21,35);
	body.push_back(31,35);
	body.push_back(35,33);
	body.push_back(36,33);
	body.push_back(38,34);
	body.push_back(37,35);
	body.push_back(35,37);
	body.push_back(32,38);
	body.push_back(32,48);
	body.push_back(34,50);
	body.push_back(33,51);
	body.push_back(30,51);
	body.push_back(29,50);
	body.push_back(28,48);
	body.push_back(27,44);
	body.push_back(26,44);
	body.push_back(25,48);
	body.push_back(24,50);
	body.push_back(23,51);
	body.push_back(20,51);
	body.push_back(19,50);
	body.push_back(21,48);
	body.push_back(21,38);
	body.push_back(18,37);
	body.push_back(16,35);
	body.push_back(14,34);

	shirt.push_back(21,34);
	shirt.push_back(18,37);
	shirt.push_back(21,38);
	shirt.push_back(21,44);
	shirt.push_back(32,44);
	shirt.push_back(32,38);
	shirt.push_back(34,37);
	shirt.push_back(32,34);
	
	pants.push_back(21,44);
	pants.push_back(21,49);
	pants.push_back(26,49);
	pants.push_back(26,47);
	pants.push_back(27,47);
	pants.push_back(27,49);
	pants.push_back(32,49);
	pants.push_back(32,44);

	parachute1.push_back(6,18);
	parachute1.push_back(11,9);
	parachute1.push_back(26,18);

	parachute2.push_back(11,9);
	parachute2.push_back(24,0);
	parachute2.push_back(26,18);

	parachute3.push_back(24,0);
	parachute3.push_back(33,0);
	parachute3.push_back(26,18);

	parachute4.push_back(33,0);
	parachute4.push_back(41,9);
	parachute4.push_back(26,18);

	parachute5.push_back(41,9);
	parachute5.push_back(46,18);
	parachute5.push_back(26,18);

	parachuteline1.push_back(6,18);
	parachuteline1.push_back(14,34);

	parachuteline2.push_back(46,18);
	parachuteline2.push_back(38,34);

	head.push_back(24,27);
	head.push_back(26,25);
	head.push_back(28,27);
	head.push_back(31,30);
	head.push_back(28,33);
	head.push_back(26,35);
	head.push_back(24,32);
	head.push_back(21,30);

	hair.push_back(24,27);
	hair.push_back(25,27);
	hair.push_back(26,25);
	hair.push_back(27,27);
	hair.push_back(28,27);

}
