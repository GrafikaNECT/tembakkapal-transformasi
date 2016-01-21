#include "printchar.h"
#include "char.h"

int main(){
	int space = 2;
	int i=0,j=0;
	// hapusScreen();
	//hapusScreen();
	initializePrinter();
	hapusScreen();
	printChar('I',100,100,1,255,255,255,255);
	//for (i=0;i<10;i++){
		//for (j=0;j<10;j++){
			//printChar('I',i*charpixmatrix_width+space,j*charpixmatrix_height+space,3,255,255,255,0);
			
		//}
	//}
	finishPrinter();
			sleep(1000);
	sleep(10000);
}
