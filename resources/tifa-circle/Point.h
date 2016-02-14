#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point {
public:
	Point() : x(0),y(0) {};
	Point(int _x, int _y) : x(_x),y(_y){ };
	int getX() { return x; };
	int getY() { return y; };

	void setX(int _x) { x = _x; };
	void setY(int _y) { y = _y; };

	void geser(int _x, int _y){ x+=_x; y+=_y;};
	Point hasilGeser(int _x, int _y) {
		Point p(getX()+_x,getY()+_y);
		return p;
	};
	Point hasilRotasi(float deltaDegree);
	Point hasilMirror00();

private:
	int x;
	int y;
};

#endif
