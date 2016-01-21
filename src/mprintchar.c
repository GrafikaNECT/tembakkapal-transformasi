#include "printchar.h"
#include "char.h"
#include <stdlib.h>

int main(){
	system("setterm -cursor off");
	int space = 2;
	int i;
	// hapusScreen();
	//hapusScreen();
	initializePrinter();

	
	hapusScreen();
	drawCharpixSquare(50, 50, 100, 0, 0, 255, 0);

	for (i=400;i>0;i--){
		printText("GRAPHICAT!!!",12,150,i,i%200,i%150,i%255,255);
		printText("Asanilta Fahda",14,150,i-25,i%200,i%150,i%255,255);
		printText("Tifani Warnita",14,150,i-50,i%200,i%150,i%255,255);
		printText("Candy Olivia M",14,150,i-75,i%200,i%150,i%255,255);
		printText("Erick Chandra",13,150,i-100,i%200,i%150,i%255,255);
		printText("M Nizami",8,150,i-125,i%200,i%150,i%255,255);
		printText("Fathul Asrar A",14,150,i-150,i%200,i%150,i%255,255);

		usleep(5000);
		printText("GRAPHICAT!!!",12,150,i,255,255,255,255);
		printText("Asanilta Fahda",14,150,i-25,255,255,255,255);
		printText("Tifani Warnita",14,150,i-50,255,255,255,255);
		printText("Candy Olivia M",14,150,i-75,255,255,255,255);
		printText("Erick Chandra",13,150,i-100,255,255,255,255);
		printText("M Nizami",14,150,i-125,255,255,255,255);
		printText("Fathul Asrar A",14,150,i-150,255,255,255,255);
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