#include "printchar.h"
#include "char.h"
#include <stdlib.h>

void drawBeveledText(char* a, int alen, int X, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha, int bevelLength,
			unsigned char bevelR, unsigned char bevelG, unsigned char bevelB, unsigned char bevelalpha){
	int drawX = X+bevelLength;
	int drawY = Y;
	int i;
	for (i=0;i<bevelLength;i++){
		printText(a,alen,drawX,drawY,size,bevelR,bevelG,bevelB,bevelalpha);
		drawX--;
		drawY++;
	}
		printText(a,alen,drawX,drawY,size,R,G,B,alpha);
}

int main(){
	system("setterm -cursor off");
	int space = 2;
	int i;
	// hapusScreen();
	//hapusScreen();

	drawPicture(1,1,1,8);
	
	initializePrinter();
	drawBeveledText("GRAPHICAT!!!",12,100,getYRes()/2-60,10,255,0,0,255,20,
				0,255,255,255);
	usleep(3000000);
	drawCanvas(0,0,0,255);
	for (i=getYRes()+1;i>-600;i--){
		printTextCentered("Asanilta Fahda",14,i+50,2,i%200,i%150,i%255,255);
		printTextCentered("Tifani Warnita",14,i+100,2,i%200,i%150,i%255,255);
		printTextCentered("Candy Olivia M",14,i+150,2,i%200,i%150,i%255,255);
		printTextCentered("Erick Chandra",13,i+200,2,i%200,i%150,i%255,255);
		printTextCentered("M Nizami",8,i+250,2,i%200,i%150,i%255,255);
		printTextCentered("Fathul Asrar A",14,i+300,2,i%200,i%150,i%255,255);

		usleep(5000);
		printTextCentered("Asanilta Fahda",14,i+50,2,0,0,0,255);
		printTextCentered("Tifani Warnita",14,i+100,2,0,0,0,255);
		printTextCentered("Candy Olivia M",14,i+150,2,0,0,0,255);
		printTextCentered("Erick Chandra",13,i+200,2,0,0,0,255);
		printTextCentered("M Nizami",8,i+250,2,0,0,0,255);
		printTextCentered("Fathul Asrar A",14,i+300,2,0,0,0,255);
		//hapusScreen();
	}

	usleep(10000);
	drawPicture(10,10,15,200);

	//for (i=0;i<10;i++){
		//for (j=0;j<10;j++){
			//printChar('I',i*charpixmatrix_width+space,j*charpixmatrix_height+space,3,255,255,255,0);
			
		//}
	//}
	system("setterm -cursor on");
	finishPrinter();
}
