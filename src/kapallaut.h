#ifndef kapallaut_h
#define kapallaut_h

#include "bullet.h"
#include "printchar.h"
#include "drawable.h"

class kapallaut: public drawable{
	public:
	kapallaut();
	kapallaut(int x,int y,float _turretAngle);
	kapallaut(int x,int y,int width,int height,float _turretAngle);
	bullet* shootBullet();
	void draw();
	void draw(int x, int y);
	void move(int deltax,int deltay);

	void turnTurretRight();
	void turnTurretLeft();

	protected:
	int x;
	int y;
	int width;
	int height;

	static const int bulletrelativex=0;
	static const int bulletrelativey=0;

	static const float turretTurnSpeed=3;
	float turretAngle;
};

#endif