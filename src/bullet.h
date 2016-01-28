#ifndef bullet_h
#define bullet_h

#include "drawable.h"

#include "line-pattern.h"

class bullet: public drawable {
	public:
	bullet(int _x1,int _x2,int _y1,int _y2, int _lifetime);
	virtual void draw();

	int getX1();
	int getY1();
	int getY2();
	int getX2();

	int getLifetime();
	void decrementLifetime();

	protected:
	int x1,x2,y1,y2;

	int lifetime;

	line_pattern defaultStyle(unsigned char gr);
	line_pattern style;
};

#endif
