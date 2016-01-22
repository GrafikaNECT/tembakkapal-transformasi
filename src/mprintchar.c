#include "printchar.h"
#include "char.h"
#include <stdlib.h>

void drawBeveledText(char* a, int alen, int X, int Y, int size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha, int bevelLength,
			unsigned char bevelR, unsigned char bevelG, unsigned char bevelB, unsigned char bevelalpha){
	int drawX = X+bevelLength;
	int drawY = Y;
	int i;
	for (i=0;i<bevelLength;i++){
		drawText(a,alen,drawX,drawY,size,bevelR,bevelG,bevelB,bevelalpha);
		drawX--;
		drawY++;
	}
		drawText(a,alen,drawX,drawY,size,R,G,B,alpha);
}

int main(){
	
	int space = 2;
	int i;

	drawPicture(1,1,1,8);
	
	if (initializePrinter()!=0) return 0;

	system("setterm -cursor off");

	drawCanvas(255,255,255,255);
	usleep(500);

	drawBeveledText("GRAPHICAT!!!",12,100,getYRes()/2-60,10,255,0,0,255,20,
				0,255,255,255);
	printToScreen();
	usleep(3000000);
	drawCanvas(0,0,0,255);
	printToScreen();

	usleep(1000000);
	drawTextCentered("0  ",3,getYRes()/3,getXRes()/64,255,0,0,0);
	printToScreen();

	usleep(1000000);
	drawTextCentered("00 ",3,getYRes()/3,getXRes()/64,255,255,0,0);
	printToScreen();

	usleep(1000000);
	drawTextCentered("000",3,getYRes()/3,getXRes()/64,255,255,255,0);
	printToScreen();

	usleep(1000000);

	drawCanvas(0,0,0,255);
	printToScreen();

	for (i=getYRes()+1;i>-600;i--){
		drawTextCentered("Asanilta Fahda",14,i+50,2,i%200,i%150,i%255,255);
		drawTextCentered("Tifani Warnita",14,i+100,2,i%200,i%150,i%255,255);
		drawTextCentered("Candy Olivia M",14,i+150,2,i%200,i%150,i%255,255);
		drawTextCentered("Erick Chandra",13,i+200,2,i%200,i%150,i%255,255);
		drawTextCentered("M Nizami",8,i+250,2,i%200,i%150,i%255,255);
		drawTextCentered("Fathul Asrar A",14,i+300,2,i%200,i%150,i%255,255);
		printToScreen();

		usleep(5000);
		drawTextCentered("Asanilta Fahda",14,i+50,2,0,0,0,255);
		drawTextCentered("Tifani Warnita",14,i+100,2,0,0,0,255);
		drawTextCentered("Candy Olivia M",14,i+150,2,0,0,0,255);
		drawTextCentered("Erick Chandra",13,i+200,2,0,0,0,255);
		drawTextCentered("M Nizami",8,i+250,2,0,0,0,255);
		drawTextCentered("Fathul Asrar A",14,i+300,2,0,0,0,255);
	}

	usleep(10000);
	drawCatPicture(50,50,15,200);
	printToScreen();

	usleep(1000000);

	system("setterm -cursor on");
	finishPrinter();
}
