#include "alphabet.h"
#include "letter.h"
#include <string>
#include <vector>
#include <ctype.h>

alphabet::alphabet() {
	initAlphabet();
}
#include <iostream>
alphabet::alphabet(std::ifstream& file){
	int width,height;
	file>>width;
	file>>height;

	default_width=width;
	default_height=height;
	
	int n;
	file>>n;
	for (int i=0;i<n;i++){
		char c;
		file>>c;
		std::cout<<"reading alphabet "<<c<<std::endl;

		int numBidang;
		file>>numBidang;

		vector<polygon> bidang(numBidang);
		for (int j=0;j<numBidang;j++){
			int numPoint;
			file>>numPoint;
			for (int k=0;k<numPoint;k++){
				int x,y;
				file>>x;
				file>>y;

				bidang[j].push_back(x,y);
			}
		}
		

		int numLubang;
		file >> numLubang;

		vector<polygon> lubang(numLubang);
		for (int j=0;j<numLubang;j++){
			int numPoint;
			file>>numPoint;
			for (int k=0;k<numPoint;k++){
				int x,y;
				file>>x;
				file>>y;

				lubang[j].push_back(x,y);
			}
		}
		
		letter l(bidang, lubang, width,height);
		letters[c]=l;

		pixelBoolMatrix pbm = l.toPixelBoolMatrix();
		for (int _y=0;_y<pbm.getHeight();_y++){
			for (int _x=0;_x<pbm.getWidth();_x++){
				std::cout<<pbm.get(_x,_y);
			}
			std::cout<<std::endl;
		}
	}
	//tambah karakter blank (spasi)
	std::vector<polygon> bidangnul(0);
	std::vector<polygon> lubangnul(0);
	letter ll(bidangnul, lubangnul, width, height);
	letters[' ']=ll;
}

void alphabet::initAlphabet() {
	//baca alphabet.txt dan isi array alphabet
}

letter alphabet::getLetter(char c) {
	return letters[c];
}
int alphabet::calculateOneCharSpace(float size){
	return (default_width+5)*size;
}

void alphabet::drawChar(char a, int X, int Y, float size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha){
	pixelBoolMatrix pbm = getLetter(a).toPixelBoolMatrix(size);
	pbm.draw(X,Y,R,G,B,alpha);
}

void alphabet::drawText(std::string a, int X, int Y, float size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha){
	int onecharspace = calculateOneCharSpace(size);
	for (int i=0;i<a.length();i++){
		drawChar(a[i],X+onecharspace*i,Y,size,R,G,B,alpha);
	}
}

void alphabet::drawTextCentered(std::string a, int Y, float size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha){
	int onecharspace = calculateOneCharSpace(size);
	int X = (getXRes()-a.length()*onecharspace)/2;
	drawText(a,X,Y,size,R,G,B,alpha);
    
}
