#include "bresenham.h"
#include <math.h>

int sign(int x){
	return (x > 0) - (x < 0);
}

void swap(int * a, int * b){	int c = *b;	*b = *a;	*a = c;}

void bresenham_drawline_notvertical(int x1, int x2, int y1, int y2){
		
	float deltax = x2-x1;
	float deltay = y2-y1;
	float error = 0;
	float deltaerr = fabs(deltay/deltax);
	int y = y1;
	int x;
	for (x = x1; x<=x2; x++){
		line_pattern_plot(x,y);
		error += deltaerr;
		while (error >= 0.5){
			line_pattern_plot(x,y);
			y = y + sign(y2-y1);
			error -= 1;
		}
	}
}

void drawline_vertical_simple(int x1, int x2, int y1, int y2){
	int y;
	int x = x1;
	for (y=y1;y<=y2;y++)
		line_pattern_plot(x,y);
}

void bresenham_drawline(int x1, int x2, int y1, int y2, line_pattern ptr){
	init_line_pattern(ptr);
	if (x2!=x1){
		if (x2>x1)
			bresenham_drawline_notvertical(x1, x2, y1, y2);
		else
			bresenham_drawline_notvertical(x2, x1, y2, y1);
	}else{
		if (y2>y1)
			drawline_vertical_simple(x1, x2, y1, y2);
		else
			drawline_vertical_simple(x2, x1, y2, y1);
	}
}
