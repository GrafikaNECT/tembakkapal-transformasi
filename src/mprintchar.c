#include "printchar.h"
#include "char.h"

int main(){
	initializePrinter();
	int space = 2;
	int i,j;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			printChar('I',i*charpixmatrix_width+2,j*charpixmatrix_height+2,255,255,255,0);
		}

	}
}
