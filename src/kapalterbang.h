#ifndef kapalterbang_h
#define kapalterbang_h

#include "bullet.h"
#include "drawable.h"
#include "movingObject.h"

class kapalterbang : public drawable, public movingObject{
	public:
		kapalterbang(int x,int y);
		kapalterbang(int _x,int _y,char* colorfile);
		kapalterbang(int x,int y,int width,int height);
		kapalterbang(int x,int y,int width,int height,char* colorfile);
		bool hitBullet(bullet b);
		void draw();
		void move(int deltax,int deltay);

		void oneFrameMove();

		int getX();
		int getY();
		int getWidth();
		int getHeight();

		bool isExploding();
		bool isDead();
		void explode();
		void setExploding(bool b);
		char* getColorFileName();
		void setColorFileName(char* file);

		void setMoveSpeedY(int v);
		int getMoveSpeedY();
		void setMoveSpeedX(int v);
		int getMoveSpeedX();
		void setScaleSpeed(float v);
		float getScaleSpeed();


	protected:
		int startX;
		int startY;
		int x;
		int y;
		int width;
		int height;
		float scale;

		//kecepatan bergerak
		int moveSpeedX;
		int moveSpeedY;
		float scaleSpeed;

		bool exploding;
		//bool dead;
		int deadlifetime=-1;
		char* colorFileName;

	private:
		//fungsi helper
		bool lineIntersectsSquare(int x1, int y1, int x2, int y2, int xBL, int yBL, int xTR, int yTR);
};

#endif
