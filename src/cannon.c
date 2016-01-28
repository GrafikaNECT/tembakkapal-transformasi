#include "cannon.h"

cannon::cannon(int _x,int _y){
	x=_x;
	y=_y;
	picmatrix = {{
	{0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0},
	{0,0,2,2,2,0,0},
	{0,0,2,2,2,0,0},
	{0,0,0,0,0,0,0}
	}};
}

void cannon::draw() {
	
}