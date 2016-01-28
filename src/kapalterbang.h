#ifndef kapalterbang_h
#define kapalterbang_h

#include "bullet.h"

class kapalterbang : drawable{
	public:
	kapalterbang(int x,int y);
	kapalterbang(int x,int y,int width,int height);
	bool hitBullet(bullet b);
	void draw();
	void move(int deltax,int deltay);

	protected:
	int x;
	int y;
	int width;
	int height;
};

#endif
