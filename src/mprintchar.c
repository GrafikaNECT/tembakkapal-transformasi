#include "printchar.h"
#include "char.h"

int main(){
	int space = 2;
	int i,j;
	// hapusScreen();
	//hapusScreen();
	initializePrinter();
	hapusScreen();
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			printChar('I',i*charpixmatrix_width+space,j*charpixmatrix_height+space,3,255,255,255,0);
			
		}
	}
	finishPrinter();
			sleep(1000);
	sleep(10000);
}
