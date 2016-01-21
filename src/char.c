#include "char.h"
#include <ctype.h>

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

charpixmatrix_type letterB = {{
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,0}}
};

charpixmatrix_type letterC = {{
	{0,0,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,1,1,1,1,0,0}}
};

charpixmatrix_type letterD = {{
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,0,0}}
};

charpixmatrix_type letterE = {{
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1}}
};

charpixmatrix_type letterF = {{
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0}}
};

charpixmatrix_type letterG = {{
	{0,0,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,1,1,1,1},
	{1,1,0,0,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,1,1,1,1,1,1}}
};

charpixmatrix_type letterH = {{
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1}}
};

charpixmatrix_type letterI = {{
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1}}
};

charpixmatrix_type letterJ = {{
	{0,0,0,0,1,1,1,1},
	{0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,1,1,1,1,0,0}}
};

charpixmatrix_type letterK = {{
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,1,1,0},
	{1,1,0,0,1,1,0,0},
	{1,1,0,1,1,0,0,0},
	{1,1,1,1,0,0,0,0},
	{1,1,1,0,0,0,0,0},
	{1,1,1,0,0,0,0,0},
	{1,1,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{1,1,0,0,1,1,0,0},
	{1,1,0,0,0,1,1,0},
	{1,1,0,0,0,0,1,1}}
};

charpixmatrix_type letterL = {{
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1}}
};

charpixmatrix_type letterM = {{
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,1,1,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1}}
};

charpixmatrix_type letterN = {{
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,0,0,0,1,1},
	{1,1,1,1,0,0,1,1},
	{1,1,1,1,1,0,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,0,0,1,1,1,1},
	{1,1,0,0,0,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1}}
};

charpixmatrix_type letterO = {{
	{0,0,1,1,1,1,0,0},
	{0,1,1,1,1,1,1,0},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{0,1,1,1,1,1,1,0},
	{0,0,1,1,1,1,0,0}}
};

charpixmatrix_type letterP = {{
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,0},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0}}
};

charpixmatrix_type letterQ = {{
	{0,0,1,1,1,1,0,0},
	{0,1,1,1,1,1,1,0},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,1,0,1,1},
	{1,1,0,0,1,1,1,1},
	{1,1,0,0,0,1,1,0},
	{0,1,1,1,1,1,1,1},
	{0,0,1,1,1,0,0,1}}
};

charpixmatrix_type letterR = {{
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,0},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,0,0},
	{1,1,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{1,1,0,0,1,1,0,0},
	{1,1,0,0,0,1,1,0},
	{1,1,0,0,0,0,1,1}}
};

charpixmatrix_type letterS = {{
	{0,0,1,1,1,1,0,0},
	{0,1,1,1,1,1,1,0},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{0,1,1,1,1,1,1,0},
	{0,0,1,1,1,1,0,0}}
};

charpixmatrix_type letterT = {{
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0}}
};

charpixmatrix_type letterU = {{
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{0,1,1,1,1,1,1,0},
	{0,0,1,1,1,1,0,0}}
};

charpixmatrix_type letterV = {{
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,0,0,1,1,1},
	{0,1,1,0,0,1,1,0},
	{0,0,1,1,1,1,0,0},
	{0,0,0,1,1,0,0,0}}
};

charpixmatrix_type letterW = {{
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,1,1,0,1,1},
	{1,1,0,1,1,0,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,0,0,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1}}
};

charpixmatrix_type letterX = {{
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{0,1,1,0,0,1,1,0},
	{0,0,1,1,1,1,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,1,1,1,1,0,0},
	{0,1,1,0,0,1,1,0},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,0,0,0,0,1,1}}
};

charpixmatrix_type letterY = {{
	{1,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,1},
	{0,1,1,0,0,1,1,0},
	{0,0,1,1,1,1,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,0}}
};

charpixmatrix_type letterZ = {{
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,1,1},
	{0,0,0,0,0,1,1,0},
	{0,0,0,0,1,1,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,1,1,0,0,0,0},
	{0,1,1,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1}}
};

charpixmatrix_type getcharpixmatrix(char C){
	switch(tolower(C)){
		case 'a':
			return letterA;
			break;
		case 'b':
			return letterB;
			break;
		case 'c':
			return letterC;
			break;
		case 'd':
			return letterD;
			break;
		case 'e':
			return letterE;
			break;
		case 'f':
			return letterF;
			break;
		case 'g':
			return letterG;
			break;
		case 'h':
			return letterH;
			break;
		case 'i':
			return letterI;
			break;
		case 'j':
			return letterJ;
			break;
		case 'k':
			return letterK;
			break;
		case 'l':
			return letterL;
			break;
		case 'm':
			return letterM;
			break;
		case 'n':
			return letterN;
			break;
		case 'o':
			return letterO;
			break;
		case 'p':
			return letterP;
			break;
		case 'q':
			return letterQ;
			break;
		case 'r':
			return letterR;
			break;
		case 's':
			return letterS;
			break;
		case 't':
			return letterT;
			break;
		case 'u':
			return letterU;
			break;
		case 'v':
			return letterV;
			break;
		case 'w':
			return letterW;
			break;
		case 'x':
			return letterX;
			break;
		case 'y':
			return letterY;
			break;
		case 'z':
			return letterZ;
			break;
		default:
			return blank;
	}
}
