#include "cannon.h"
#include "print.h"
#include <math.h>

using namespace std;

cannon::cannon(int _x,int _y){
	x=_x;
	y=_y;
	angle = 0;
}

cannon::cannon(int _x,int _y, int _angle){
	x=_x;
	y=_y;
	angle = _angle*PI/180.0;
}

cannon::~cannon() {

}

void cannon::draw() {
	for (int i=0;i<5;i++) {
		for (int j=0;j<7;j++) {
			int* RGBA = getRGBA(picmatrix[i][j]);
			int newx = rotateX(x+j,y+i);
			int newy = rotateY(x+j,y+i);
			drawCharpixSquare(newx,newy,5,RGBA[0],RGBA[1],RGBA[2],RGBA[3]);
		}
	}	
}

int cannon::rotateX(int x, int y) {
	return (x*cos(angle)-y*sin(angle));
}

int cannon::rotateY(int x, int y) {
	return (x*sin(angle)+y*cos(angle));
}

int* cannon::getRGBA(int n) {
	int RGBA[4];
	switch (n) {
		case 0: { RGBA[0] = 0; RGBA[1] = 0; RGBA[2] = 0; RGBA[3] = 0; break; }
		case 1: { RGBA[0] = 50; RGBA[1] = 43; RGBA[2] = 47; RGBA[3] = 255; break; }
		case 2: { RGBA[0] = 89; RGBA[1] = 75; RGBA[2] = 82; RGBA[3] = 255; break; }
	}
}

void cannon::erase() {
	for (int i=0;i<5;i++) {
		for (int j=0;j<7;j++) {
			int newx = rotateX(x+j,y+i);
			int newy = rotateY(x+j,y+i);
			drawPix(newx,newy,0,0,0,255);
		}
	}
}
void cannon::rotate() {
	if (angle>(-90*PI/180)) {
		erase();
		angle = (angle-1)*PI/180;
		draw();
	}	
}

void cannon::rotateCounter() {
	if (angle<(90*PI/180.0)) {
		erase();
		angle = (angle+1)*PI/180;
		draw();
	}
}