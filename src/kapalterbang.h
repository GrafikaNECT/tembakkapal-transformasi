#ifndef kapalterbang_h
#define kapalterbang_h

#include "bullet.h"

class kapalterbang : public drawable{
	public:
	kapalterbang(int x,int y);
	kapalterbang(int x,int y,int width,int height);
	bool hitBullet(bullet b);
	void draw();
	void move(int deltax,int deltay);

	int getX();
	int getY();
	int getWidth();
	int getHeight();

	bool isExploding();
	void explode();
	void setExploding(bool b);

	protected:
	int x;
	int y;
	int width;
	int height;

	bool exploding;

	private:
	//fungsi helper
	bool lineIntersectsSquare(int x1, int y1, int x2, int y2, int xBL, int yBL, int xTR, int yTR);
};

#endif
