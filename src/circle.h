#ifndef circle_h
#define circle_h

#define ROTATE_RADIUS 30

typedef struct {
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char alpha;
	int radius;
	int x;
	int y;
} circle;

circle makeCircle(
	unsigned char R,
	unsigned char G,
	unsigned char B,
	unsigned char alpha,
	int radius,
	int x,
	int y);

void drawCircle(circle C);

#endif