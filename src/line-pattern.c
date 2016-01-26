#include "line-pattern.h"
#include "printchar.h"

line_pattern makeLinePattern(
	unsigned char * R,
	unsigned char * G,
	unsigned char * B,
	unsigned char * Alpha,
	int length){
	line_pattern retval;
	int i;
	for (i=0;i<length;i++)
		retval.R[i]=R[i];
	for (i=0;i<length;i++)
		retval.G[i]=G[i];
	for (i=0;i<length;i++)
		retval.B[i]=B[i];
	for (i=0;i<length;i++)
		retval.Alpha[i]=Alpha[i];
	retval.length = length;
	return retval;
}

line_pattern current_line_pattern;
int current_line_pattern_idx;

void init_line_pattern(line_pattern ptr){
	current_line_pattern = ptr;
	current_line_pattern_idx=0;
}

#include <stdio.h>

void line_pattern_plot(int x, int y){
	drawPix(x,y,
		current_line_pattern.R[current_line_pattern_idx],
		current_line_pattern.G[current_line_pattern_idx],
		current_line_pattern.B[current_line_pattern_idx],
		current_line_pattern.Alpha[current_line_pattern_idx]);
	current_line_pattern_idx ++;
	if (current_line_pattern_idx>=current_line_pattern.length) current_line_pattern_idx=0;
}
