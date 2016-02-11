#ifndef point_h
#define point_h

class point{
	private:
	int x;
	int y;

	public:
	point():x(0),y(0){};
	point(int _x, int _y):x(_x),y(_y){};
	int getX(){return x;};
	int getY(){return y;};

	void setX(int _x){x=_x;};
	void setY(int _y){y=_y;};

	void geser(int _x, int _y){x+=_x; y+=_y;};
	point hasilGeser(int _x, int _y){
		point p(getX()+_x,getY()+_y);
		return p;
	};
	point hasilRotasi(float deltaDegree);
	point hasilMirror00();
};

#endif
