#ifndef polygon_h
#define polygon_h

#include <vector>
#include "point.h"

class polygon: public std::vector<point>{
	public:
	polygon():std::vector<point>(){};
	polygon(std::vector<point>::size_type s):std::vector<point>(s){};
	polygon hasilGeser(point delta);
	polygon hasilGeser(int deltax, int deltay);
	polygon hasilPerbesar(float scale);

	polygon hasilSkala(float scaleX, float scaleY);
	polygon hasilRotasi(float deltaDegree);
	polygon hasilRotasi(float deltaDegree, point poros);

	void push_back(int x, int y); 
	void push_back(const point& p){std::vector<point>::push_back(p);};

	void draw(int x, int y, int R, int G, int B, int A, bool wireframeOnly=false);

	private:
	
};

#endif
