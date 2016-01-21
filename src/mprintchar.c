#include "printchar.h"
#include "char.h"
#include <stdlib.h>

int main(){
	system("setterm -cursor off");
	int space = 2;
	int i=0,j=0;
	// hapusScreen();
	//hapusScreen();
	initializePrinter();
	hapusScreen();
	for (i=0;i<1000;i++){
		printText("NIZAMI EC CANDY TIFA NILTA",7,100,100+i,i%200,i%150,i%255,255);
		usleep(5000);
		printText("NIZAMI EC CANDY TIFA NILTA",7,100,100+i,255,255,255,255);
		//hapusScreen();
	}
	//for (i=0;i<10;i++){
		//for (j=0;j<10;j++){
			//printChar('I',i*charpixmatrix_width+space,j*charpixmatrix_height+space,3,255,255,255,0);
			
		//}
	//}
	system("setterm -cursor on");
	finishPrinter();
}
