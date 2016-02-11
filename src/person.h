#ifndef person_h
#define person_h

#include "polygon.h"
#include "circle.h"
#include <vector>

using namespace std;

class person : public drawable, public movingObject {
	public:
	person();

	protected:
	polygon body;
	polygon shirt;
	polygon pants;
	circle head;
	polygon parachute;
	line* parachute_lines;

};

#endif
