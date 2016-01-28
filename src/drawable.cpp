#include "drawable.h"

bool drawable::operator< (const drawable& rhs){
	return level < rhs.level;
}

void drawable::setLevel(int _level){
	level=_level;
}

int drawable::getLevel(){
	return level;
}
