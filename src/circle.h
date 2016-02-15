#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "print.h"
#include "point.h"

using namespace std;

class circle {
public:
	circle() : centerPoint(0,0), radius(0), degree(2), R(255), G(255), B(255), alpha(255) {};
	circle(int x, int y, int r, int d) : centerPoint(x,y), radius(r), degree(d), R(255), G(255), B(255), alpha(255) {};
	
	point getCenterPoint() { return centerPoint; };
	int getRadius() { return radius; };
	int getDegree() { return degree; };
	
	void drawCircle(unsigned int _R, unsigned int _G, unsigned int _B, unsigned int _alpha, bool half, bool solid);

private:
	point centerPoint;
	int radius;
	int degree;

	unsigned int R;
	unsigned int G;
	unsigned int B;
	unsigned int alpha;

	void plot4points(int x, int y, bool half, bool solid);
	void plot8points(int x, int y, bool half, bool solid);
};

#endif