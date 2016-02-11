#include "person.h"
#include "print.h"
#include "cmath.h"

void person::oneFrameMove(){
	//terkait kecepatan
	gravity_accelerate();
	drag();

	move();
}

void person::draw(){
	//TODO GANTI JADI BUKAN KOTAK
	polygon p;
	p.push_back(-30,-20);
	p.push_back(30,-20);
	p.push_back(30,80);
	p.push_back(-30,80);

	polygon protate = p.hasilRotasi(rotateDegree);
	protate.draw(x,y,0,255,255,255);
	
}


