#ifndef person_h
#define person_h

#include "drawable.h"
#include "movingObject.h"
#include "polygon.h"
#include "circle.h"
#include <vector>
#include <random>

using namespace std;

class person : public drawable, public movingObject {
	public:
	person();

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
	polygon parachute1;
	polygon parachute2;
	polygon parachute3;
	polygon parachute4;
	polygon parachute5;
//	line* parachute_lines;
//	line belum ada. fathul udah bikin tapi point-nya agak beda gitu jadi harus disesuaikan

//terkait pergerakan
	static const float miring_xnambah_coeff = 1;
	static const float gravity_accel= 1;
	static const float maxYSpeed = 3;
	static const float maxXSpeed = 5;
	static const float osc_coeff = 1;
	static const float osc_damp_coeff = 0.1;
	int xSpeed;
	int ySpeed;

	float rotateDegreeAccel;
	float rotateDegreeSpeed;

	static const float maxDegree = 40;

	void gravity_accelerate();
	void drag();
	void changeMiring();

	void move();

	void initShape();

	static std::default_random_engine rd;
	static std::normal_distribution<double> rotateDegreeRandomGenerator;
};

#endif
