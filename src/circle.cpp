#include "bresenham.h"
#include "circle.h"

using namespace std;

void circle::drawCircle(unsigned int _R, unsigned int _G, unsigned int _B, unsigned int _alpha, bool half, bool solid) {
	int error = -radius;
	int x = radius;
	int y = 0;

	R = _R;
	G = _G;
	B = _B;
	alpha = _alpha;

	while (x >= y) {
		plot8points(x, y, half, solid);
		error+=y;
		y++;
		error+=y;

		if (error >= 0) {
			error += -x;
			x--;
			error += -x;
		}
	}
}

void circle::plot4points(int x, int y, bool half, bool solid) {
	if (!solid) {
		drawPix(getCenterPoint().getX()+x, getCenterPoint().getY()-y, R, G, B, alpha);
		drawPix(getCenterPoint().getX()-x, getCenterPoint().getY()-y, R, G, B, alpha);
		if (!half) {
			drawPix(getCenterPoint().getX()+x, getCenterPoint().getY()+y, R, G, B, alpha);
			drawPix(getCenterPoint().getX()-x, getCenterPoint().getY()+y, R, G, B, alpha);
		}
	} else { // Harusnya pake bressenham line
		line_pattern allBlack;

		unsigned char AllBlackR[] ={R};
		unsigned char AllBlackG[] ={G};
		unsigned char AllBlackB[] ={B};
		unsigned char AllBlackA[] ={alpha};

		allBlack = makeLinePattern(AllBlackR,AllBlackG,AllBlackB,AllBlackA,1);
		bresenham_drawline(getCenterPoint().getX()+x, getCenterPoint().getY()-y,getCenterPoint().getX(), getCenterPoint().getY(), allBlack);
		printToScreen();
		bresenham_drawline(getCenterPoint().getX()-x, getCenterPoint().getY()-y,getCenterPoint().getX(), getCenterPoint().getY(), allBlack);
		printToScreen();
		if (!half) {
			bresenham_drawline(getCenterPoint().getX()+x, getCenterPoint().getY()+y,getCenterPoint().getX(), getCenterPoint().getY(), allBlack);
			printToScreen();
			bresenham_drawline(getCenterPoint().getX()-x, getCenterPoint().getY()+y,getCenterPoint().getX(), getCenterPoint().getY(), allBlack);
			printToScreen();
		}
	}
}

void circle::plot8points(int x, int y, bool half, bool solid) {
	plot4points(x, y, half, solid);
	plot4points(y, x, half, solid);
}

/*void circle::moveCircle(circle C, int dx, int dy) {
	C.x += dx;
	C.y += dy;
}

void circle::rotateCircle(circle C, int angle, int rotate_x, int rotate_y) {
	C.x = cos(angle) * ROTATE_RADIUS + rotate_x;
	C.y = sin(angle) * ROTATE_RADIUS + rotate_y; 
}*/