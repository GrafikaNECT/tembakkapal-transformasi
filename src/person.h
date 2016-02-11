#ifndef person_h
#define person_h

#include "polygon.h"
#include "circle.h"
#include <vector>

using namespace std;

class person : public drawable, public movingObject {
	public:
	person(){};

	void setX(int _x){x=_x;}
	void setY(int _y){y=_y;}
	void setRotateDegree(float _r){rotateDegree=_r;}

	void oneFrameMove();
	void draw();

	protected:
	int x;
	int y;
	float rotateDegree;

	polygon body;
	polygon shirt;
	polygon pants;
	circle head;
	polygon parachute;
//	line* parachute_lines;
//	line belum ada. fathul udah bikin tapi point-nya agak beda gitu jadi harus disesuaikan

//terkait pergerakan
	static const int gravity_accel;
	static const float drag_coefficients;
	int xSpeed;
	int ySpeed;

	void gravity_accelerate();
	void drag();

	void move();

};

#endif
