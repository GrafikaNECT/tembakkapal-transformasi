#include "circle.h"
#include "print.h"
#include <math.h>


circle makeCircle(
	unsigned char R,
	unsigned char G,
	unsigned char B,
	unsigned char alpha,
	int radius,
	int x,
	int y) {
	circle C;
	C.R = R;
	C.G = G;
	C.B = B;
	C.alpha = alpha;
	C.radius = radius;
	C.x = x;
	C.y = y;
}

void drawCircle(circle C) {
	inline void plot4points(circle C, int x, int y) {
		drawPix(C.x+x, C.y+y, C.R, C.G, C.B, C.alpha);
		drawPix(C.x-x, C.y+y, C.Rc, C.G, C.B, C.alpha);
		drawPix(C.x+x, C.y-y, C.R, C.G, C.B, C.alpha);
		drawPix(C.x-x, C.y-y, C.R, C.G, C.B, C.alpha);
	}
	inline void plot8points(circle C, int x, int y) {
		plot4points(C, x, y);
		plot4points(C, y, x);
	}
	int error = -C.radius;
	int x = C.radius;
	int y = 0;

	while (x >= y) {
		plot8points(C, x, y);
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

void moveCircle(circle C, int dx, int dy) {
	C.x += dx;
	C.y += dy;
}

void rotateCircle(circle C, int angle, int rotate_x, int rotate_y) {
	C.x = cos(angle) * ROTATE_RADIUS + rotate_x;
	C.y = sin(angle) * ROTATE_RADIUS + rotate_y; 
}