#ifndef banterbakar_h
#define banterbakar_h

#include <random>
#include "drawable.h"
#include "movingObject.h"

class banterbakar: public drawable, public movingObject{
	public:

	banterbakar(){xSpeed = speedRandomGenerator(rd); ySpeed = speedRandomGenerator(rd);};

	banterbakar(int _x, int _y, int baseXSpeed, int baseYSpeed);
	


	//bila di-attach, akan diset oleh pesawat
	void setX(int x);
	void setY(int y);

	void draw();
	void oneFrameMove();

	private:
	//untuk gambar, lihat empat variabel ini:
	int x; //ini x pusat
	int y; //ini y pusat

	//tambahan untuk gambar
	static const int width = 40;
	static const int height = 40;

	float bounceelasticity=0.8;

	//hanya relevan bila sudah lepas
	int xSpeed;
	int ySpeed;
	static const int fallaccel = 1;

	//randomisasi
	static std::default_random_engine rd;
	static std::normal_distribution<double> speedRandomGenerator;
	
};

#endif
