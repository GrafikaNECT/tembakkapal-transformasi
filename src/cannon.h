#ifndef cannon_h
#define cannon_h

#define PI 3.14159265359

class cannon {
	public:
	cannon(int x,int y);
	cannon(int x, int y, int angle);
	~cannon();
	void draw();
	void rotate();
	void rotateCounter();

	protected:
	int picmatrix[5][7] = {
	{0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0},
	{0,0,2,2,2,0,0},
	{0,0,2,2,2,0,0},
	{0,0,0,0,0,0,0}
	};
	int x;
	int y;
	double angle;

	private:
	int rotateX(int x, int y);
	int rotateY(int x, int y);
	int* getRGBA(int n);
};

#endif
