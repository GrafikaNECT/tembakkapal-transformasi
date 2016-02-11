#include "point.h"

#include <cmath>
point point::hasilRotasi(float deltaDegree){
	float deltaRad = deltaDegree*M_PI/180.0;
	point p((double)x*cos(deltaRad)-(double)y*sin(deltaRad),(double)x*sin(deltaRad)+(double)y*cos(deltaRad));
	return p;
}

point point::hasilMirror00(){
	point p(-x,-y);
	return p;
}
