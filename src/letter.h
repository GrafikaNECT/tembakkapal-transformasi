#ifndef letter_h
#define letter_h

#include "polygon.h"
#include "pixelBoolMatrix.h"
#include <vector>

using namespace std;

class letter {
	public:
	letter(){};
	letter(vector<polygon> bidang, vector<polygon> lubang, int width, int height);
	//~letter();

	//mengubah ke pixelBoolMatrix
	//bila resize lebih dari 1, yang didapat adalah pixelBoolMatrix yang diperbesar
	pixelBoolMatrix toPixelBoolMatrix(float resize = 1);

	protected:
	vector<polygon> bidang;
	vector<polygon> lubang;
	int width;
	int height;
};

#endif
