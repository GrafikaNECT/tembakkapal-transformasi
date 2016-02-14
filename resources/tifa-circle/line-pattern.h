#ifndef line_pattern_h
#define line_pattern_h

#define LINE_PATTERN_MAX_LENGTH 1792

typedef struct {
	unsigned char R[1792];
	unsigned char G[1792];
	unsigned char B[1792];
	unsigned char Alpha[1792];
	int length;
}line_pattern;

line_pattern makeLinePattern(
	unsigned char * R,
	unsigned char * G,
	unsigned char * B,
	unsigned char * Alpha,
	int length);

void init_line_pattern(line_pattern ptr);

void line_pattern_plot(int x, int y);

#endif
