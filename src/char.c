#include "char.h"

charpixmatrix_type blank = {{
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}}
};

charpixmatrix_type letterI = {{
	{0,1,1,1,1,1,1,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,1,1,1,1,1,1,0}}
};

charpixmatrix_type letterA = {{
	{0,0,1,1,1,1,0,0},
	{0,0,1,1,1,1,0,0},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1}
}};

charpixmatrix_type getcharpixmatrix(char C){
	switch(C){
		case 'i':
		case 'I':
		return letterI;
		default:
		return blank;
	}
}
