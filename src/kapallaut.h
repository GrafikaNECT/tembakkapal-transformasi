#ifndef kapallaut_h
#define kapallaut_h

#include "bullet.h"
#include "printchar.h"
#include "drawable.h"
#define PI 3.14159265
class kapallaut: public drawable{
	public:
	kapallaut();
	kapallaut(int x,int y,float _turretAngle);
	kapallaut(int x,int y,int width,int height,float _turretAngle);
	bullet* shootBullet();
	void draw();
	void draw(int x, int y);

	void moveRight();
	void moveLeft();
	void turnTurretRight();
	void turnTurretLeft();

	protected:
	int x;
	int y;
	int width;
	int height;

	static const int bulletrelativex=0;
	static const int bulletrelativey=0;

	static const float turretTurnSpeed=PI/30;
	static const int shipSpeed = 5;
	float turretAngle;
};

#endif
