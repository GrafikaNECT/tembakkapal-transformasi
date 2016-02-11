#ifndef alphabet_h
#define alphabet_h

#include "letter.h"
#include <map>

#include <string>

#include <fstream>

class alphabet {
	public:
	alphabet();
	alphabet(std::ifstream& file);
	void initAlphabet();
	letter getLetter(char c);

	void drawChar(char a, int X, int Y, float size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);
	void drawText(std::string a, int X, int Y, float size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);
	void drawTextCentered(std::string a, int Y, float size, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

	protected:
	std::map<char, letter> letters;
	int default_width,default_height;

	int calculateOneCharSpace(float size);
};

#endif
