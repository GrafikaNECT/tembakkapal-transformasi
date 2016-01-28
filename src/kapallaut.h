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
	void move(int deltax,int deltay);

	void turnTurretRight();
	void turnTurretLeft();

	protected:
	int x;
	int y;
	int width;
	int height;

	static const int bulletrelativex=15;
	static const int bulletrelativey=40;

	static const float turretTurnSpeed=PI/30;
	float turretAngle;

	//helper
	void drawTurret();
};

#endif
