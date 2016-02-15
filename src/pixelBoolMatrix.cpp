#include "pixelBoolMatrix.h"
#include "print.h"

#include <math.h>
#include <queue>

pixelBoolMatrix::pixelBoolMatrix(int _width, int _height):width(_width),height(_height){
	tab.resize(width);
	for (int i=0;i<width;i++){
		tab[i].resize(height);
	}
};


pixelBoolMatrix::pixelBoolMatrix(const pixelBoolMatrix& rhs){
	tab.resize(width);
	for (int i=0;i<width;i++){
		tab[i].resize(height);
		for (int j=0;j<height;j++)
			tab[i][j]=rhs.tab[i][j];
	}
}

pixelBoolMatrix& pixelBoolMatrix::operator=(const pixelBoolMatrix& rhs){
	tab.resize(width);
	for (int i=0;i<width;i++){
		tab[i].resize(height);
		for (int j=0;j<height;j++)
			tab[i][j]=rhs.tab[i][j];
	}

}

pixelBoolMatrix::~pixelBoolMatrix(){
}

void pixelBoolMatrix::draw(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha){
	for (int i=0;i<width;i++){
		for (int j=0;j<height;j++){
			if (tab[i][j])
				drawPix(x+i,y+j,R,G,B,Alpha);
		}
	}
}
void pixelBoolMatrix::draw(point p, unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha){
	draw(p.getX(),p.getY(),R,G,B,Alpha);
}

void pixelBoolMatrix::set(int x, int y, bool menyala){
	if (x>=0 && y >= 0 &&x<width && y <height)
		tab[x][y]=menyala;
}
void pixelBoolMatrix::set(point p, bool menyala){
	set(p.getX(),p.getY(),menyala);
}

void pixelBoolMatrix::setAll(bool menyala){
	for (int i=0;i<width;i++){
		for (int j=0;j<height;j++){
			set(i,j,menyala);
		}
	}
}

bool pixelBoolMatrix::get(int x, int y){
	return tab[x][y];
}
bool pixelBoolMatrix::get(point p){
	return get(p.getX(),p.getY());
}

int pixelBoolMatrix::getWidth(){
	return width;
}
int pixelBoolMatrix::getHeight(){
	return height;
}

void pixelBoolMatrix::setLine(int x1, int x2, int y1, int y2, bool menyala){
	bresenham_drawline(x1,x2,y1,y2,menyala);
}
void pixelBoolMatrix::setLine(point p1, point p2, bool menyala){
	setLine(p1.getX(),p2.getX(),p1.getY(),p2.getY(),menyala);
}

void pixelBoolMatrix::fill(int xIgnition, int yIgnition, bool menyala){
	point p(xIgnition,yIgnition);
	fill(p,menyala);
}

void pixelBoolMatrix::fill (point pIgnition, bool menyala){
	std::queue<point> pointsToFill;
	pointsToFill.push(pIgnition);

	while (!pointsToFill.empty()){
		point p = pointsToFill.front();
		pointsToFill.pop();

		if (p.getX()>=0 && p.getY()>=0 &&p.getX()<getWidth() && p.getY()<getHeight())
		if (get(p)!=menyala){
			//mengisi
			set(p,menyala);

			//menaruh tetangganya di dalam queue
			pointsToFill.push(p.hasilGeser(1,0));
			pointsToFill.push(p.hasilGeser(-1,0));
			pointsToFill.push(p.hasilGeser(0,1));
			pointsToFill.push(p.hasilGeser(0,-1));
		}
	}
}

void pixelBoolMatrix::setWireframe(polygon p, bool menyala){
	int i;
	for (i=0;i<p.size()-1;i++){
		setLine(p[i],p[i+1],menyala);
	}
	setLine(p[i],p[0],menyala);
}

#include<algorithm>

void pixelBoolMatrix::setSolid(polygon p, bool menyala){
//TODO ganti jadi yang dibagi jadi segitiga-segitiga
	//===gambar wireframe===
	setWireframe(p,menyala);

	

	//coba fill pakai point-in-polygon http://alienryderflex.com/polygon_fill/
	//TODO tukar loop x dan y supaya cepat (mungkin, cobain)
	for (int y=0;y<getHeight();y++){
		//ambil intersection dengan garis
		std::vector<int> intersections;
		for (int i=0;i<p.size()-1;i++){
			if (p[i].getY()!=p[i+1].getY())
			if ((y<p[i].getY() && y >= p[i+1].getY()) ||
				(y>=p[i].getY() && y < p[i+1].getY())){				
					int x=(int)((p[i].getX()+((float)y-p[i].getY())/((float)p[i+1].getY()-p[i].getY())*(p[i+1].getX()-p[i].getX())));
				intersections.push_back(x);
			}
		}
		int i=p.size()-1;
		if (p[i].getY()!=p[0].getY())
		if ((y<p[i].getY() && y >= p[0].getY()) ||
			 (y>=p[i].getY() && y < p[0].getY())){
			int x=(int)((p[i].getX()+((float)y-p[i].getY())/((float)p[0].getY()-p[i].getY())*(p[0].getX()-p[i].getX())));
			intersections.push_back(x);
		}

		std::sort(intersections.begin(),intersections.end());

		for (int i=0;i<intersections.size();i+=2){
			if (intersections[i]>=getWidth()) break;
			if (intersections[i+1]>0){
				if (intersections[i]<0) intersections[i]=0;
				if (intersections[i+1]>getWidth()) intersections[i+1]=getWidth();
				for (int x=intersections[i];x<intersections[i+1];x++)
					set(x,y,menyala);
			}
		}
	}
}


//helper
int pixelBoolMatrix::sign(int x){
	return (x > 0) - (x < 0);
}

void pixelBoolMatrix::swap(int * a, int * b){	int c = *b;	*b = *a;	*a = c;}

void pixelBoolMatrix::bresenham_drawline_notvertical(int x1, int x2, int y1, int y2, bool menyala){
		
	float deltax = x2-x1;
	float deltay = y2-y1;
	float error = 0;
	float deltaerr = fabs(deltay/deltax);
	int y = y1;
	int x;
	for (x = x1; x<=x2; x++){
		set(x,y,menyala);
		error += deltaerr;
		while (error >= 0.5){
			set(x,y,menyala);
			y = y + sign(y2-y1);
			error -= 1;
		}
	}
}

void pixelBoolMatrix::drawline_vertical_simple(int x1, int x2, int y1, int y2, bool menyala){
	int y;
	int x = x1;
	for (y=y1;y<=y2;y++)
		set(x,y,menyala);
}

void pixelBoolMatrix::bresenham_drawline(int x1, int x2, int y1, int y2, bool menyala){
	if (x2!=x1){
		if (x2>x1)
			bresenham_drawline_notvertical(x1, x2, y1, y2, menyala);
		else
			bresenham_drawline_notvertical(x2, x1, y2, y1, menyala);
	}else{
		if (y2>y1)
			drawline_vertical_simple(x1, x2, y1, y2, menyala);
		else
			drawline_vertical_simple(x2, x1, y2, y1, menyala);
	}
}
