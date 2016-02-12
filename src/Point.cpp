#include "Point.h"

using namespace std;

Point Point::hasilRotasi(float deltaDegree) {
	float deltaRad = deltaDegree*M_PI/180.0;
	Point p((double)x*cos(deltaRad)-(double)y*sin(deltaRad),(double)x*sin(deltaRad)+(double)y*cos(deltaRad));
	return p;
}

Point Point::hasilMirror00() {
	Point p(-x,-y);
	return p;
}
