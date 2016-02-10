#ifndef kapallaut_h
#define kapallaut_h

#include "bullet.h"
#include "print.h"
#include "drawable.h"

#include <vector>
#include "line-pattern.h"


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

	void switchShootStyle();

	int getHeight();

	protected:
	int x;
	int y;
	int width;
	int height;

	static const int bulletrelativex=15;
	static const int bulletrelativey=40;

	static const float turretTurnSpeed=PI/30;
	static const int shipSpeed = 5;
	float turretAngle;

	static std::vector<line_pattern> initShootStyles();
	static const std::vector<line_pattern> shootStyles;
	int shootStyleNum;

	//helper
	void drawTurret();
};

#endif
