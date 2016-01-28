#ifndef kapallaut_h
#define kapallaut_h

#include "bullet.h"
#include "printchar.h"

class kapallaut: public drawable{
	public:
	kapallaut(int x,int y);
	kapallaut(int x,int y,int width,int height);
	//bullet shootBullet(int x);
	void draw(int x, int y);
	void move(int deltax,int deltay);

	protected:
	int x;
	int y;
	int width;
	int height;
};

#endif
