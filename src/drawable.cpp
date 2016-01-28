#include "drawable.h"

bool drawable::operator< (const drawable& rhs){
	return level < rhs.level;
}
