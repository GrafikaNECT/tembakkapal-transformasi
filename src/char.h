#ifndef char_h
#define char_h

#include <stdbool.h>

#define charpixmatrix_width 8
#define charpixmatrix_height 12

typedef struct {
	bool tab[charpixmatrix_height][charpixmatrix_width];
} charpixmatrix_type;

charpixmatrix_type getcharpixmatrix(char a);

#endif
