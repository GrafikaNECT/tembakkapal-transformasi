#include "alphabet.h"
#include "print.h"
#include "pixelBoolMatrix.h"
#include <fstream>
#include <unistd.h>
#include <iostream>

void testPrintChar(alphabet mainalphabet, char c){

		std::cout<<"printing: "<<c<<std::endl;
		drawCanvas(0,0,0,255);
		mainalphabet.drawChar(c,20,20,20,255,255,255,255);		
		printToScreen();
}

void testPrintText(alphabet mainalphabet, std::string s){

		std::cout<<"printing: "<<s<<std::endl;
		drawCanvas(0,0,0,255);
		mainalphabet.drawText(s,20,20,3,255,255,255,255);		
		printToScreen();
}

void testPrintTextCentered(alphabet mainalphabet, std::string s){

		std::cout<<"printing: "<<s<<std::endl;
		drawCanvas(0,0,0,255);
		mainalphabet.drawTextCentered(s,20,3,255,255,255,255);		
		printToScreen();
}

int main(){
	ifstream alphabetfile;
	alphabetfile.open("alphabet-2.txt");
	alphabet mainalphabet(alphabetfile);
	alphabetfile.close();

	initializePrinter();
	for (char c = 'A';c<'X';c++){
		testPrintChar(mainalphabet, c);
		usleep(30000);
	}
	testPrintChar(mainalphabet, 'Y');
		usleep(30000);
		testPrintChar(mainalphabet, 'Z');
		usleep(30000);
		testPrintChar(mainalphabet, '!');
		usleep(30000);
		testPrintChar(mainalphabet, '.');
		usleep(30000);
		testPrintText(mainalphabet, "ABCDEFGH");
		usleep(300000);
		testPrintTextCentered(mainalphabet, "ABCDEFGH");
		usleep(300000);
	finishPrinter();
}
