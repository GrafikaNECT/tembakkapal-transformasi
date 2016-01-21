#include "printchar.h"
#include "char.h"

int main(){
	int space = 2;
	int i=0,j=0;
	// hapusScreen();
	//hapusScreen();
	initializePrinter();
	for (i=0;i<1000;i++){
		hapusScreen();
		printText("IIIIIII",7,100,100+i,0,0,0,255);
		usleep(10000);
	}
	//for (i=0;i<10;i++){
		//for (j=0;j<10;j++){
			//printChar('I',i*charpixmatrix_width+space,j*charpixmatrix_height+space,3,255,255,255,0);
			
		//}
	//}
	finishPrinter();
}
