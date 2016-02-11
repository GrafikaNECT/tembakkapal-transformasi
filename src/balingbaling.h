#ifndef balingbaling_h
#define balingbaling_h

#include "drawable.h"
#include "movingObject.h"

class balingbaling: public drawable, public movingObject{
	public:

	//bila di-attach, akan diset oleh pesawat
	void setX(int x);
	void setY(int y);
	void setScale(float scale);

	void setRotateSpeed(float rotateSpeed);

	void draw();
	void oneFrameMove();

	void attach();
	void detach(int xSpeed, int ySpeed);
	
	private:
	//untuk gambar, lihat empat variabel ini:
	int x; //ini x pusat
	int y; //ini y pusat
	float scale;
	float rotateDegree;

	//tambahan untuk gambar
	static const int width = 20;
	static const int height = 20;

	//untuk update
	float rotateSpeed;

	bool attached;

	//hanya relevan bila sudah lepas
	int xSpeed;
	int ySpeed;
	static const int fallaccel = 1;

};

#endif
