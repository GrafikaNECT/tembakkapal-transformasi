#ifndef pixelboolmatrix_h
#define pixelboolmatrix_h

#include <vector>
#include "print.h"
#include "point.h"
#include "polygon.h"

class pixelBoolMatrix{
	public:
	pixelBoolMatrix(int _width, int _height);
	pixelBoolMatrix(const pixelBoolMatrix& rhs);
	pixelBoolMatrix& operator=(const pixelBoolMatrix& rhs);
	~pixelBoolMatrix();

	void draw(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha);
	void draw(point p, unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha);

	void set(int x, int y, bool menyala);
	void set(point p, bool menyala);

	void setAll(bool menyala);

	bool get(int x, int y);
	bool get(point p);

	int getWidth();
	int getHeight();

	void setLine(int x1, int y1, int x2, int y2, bool menyala);
	void setLine(point p1, point p2, bool menyala);

	void fill(int xIgnition, int yIgnition, bool menyala);
	void fill (point pIgnition, bool menyala);

	void setWireframe(polygon p, bool menyala);
	void setSolid(polygon p, bool menyala);

	private:
	int width,height;
	std::vector<std::vector<bool> >tab;

	int sign(int x);

	void swap(int * a, int * b);

	void bresenham_drawline_notvertical(int x1, int x2, int y1, int y2, bool menyala);	

	void drawline_vertical_simple(int x1, int x2, int y1, int y2, bool menyala);

	void bresenham_drawline(int x1, int x2, int y1, int y2, bool menyala);
};

#endif
