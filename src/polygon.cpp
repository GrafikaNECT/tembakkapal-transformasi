#include "polygon.h"
#include "pixelBoolMatrix.h"

void polygon::push_back(int x, int y){
	point p(x,y);
	push_back(p);
}

polygon polygon::hasilGeser(point delta){
	return hasilGeser(delta.getX(), delta.getY());
}

polygon polygon::hasilGeser(int deltax, int deltay){
	polygon retval = *this;
	for (int i=0;i<std::vector<point>::size();i++){
		retval[i].geser(deltax,deltay);
	}
	return retval;
}
polygon polygon::hasilPerbesar(float scale){
	polygon retval = *this;
	for (int i=0;i<std::vector<point>::size();i++){
		point& p = retval[i];
		p.setX(p.getX()*scale);
		p.setY(p.getY()*scale);
	}
	return retval;
}

polygon polygon::hasilSkala(float scaleX, float scaleY){
	polygon retval = *this;
	for (int i=0;i<std::vector<point>::size();i++){
		point& p = retval[i];
		p.setX(p.getX()*scaleX);
		p.setY(p.getY()*scaleY);
	}
	return retval;
}

polygon polygon::hasilRotasi(float deltaDegree){
	polygon retval(std::vector<point>::size());
	for (int i=0;i<std::vector<point>::size();i++){
		const point& p = at(i);
		retval[i]=p.hasilRotasi(deltaDegree);
	}
	return retval;	
}

polygon polygon::hasilRotasi(float deltaDegree, point poros){
	polygon tmp1 = hasilGeser(poros.hasilMirror00());
	polygon tmp2 = tmp1.hasilRotasi(deltaDegree);
	return tmp2.hasilGeser(poros);
}

void polygon::draw(int x, int y, int R, int G, int B, int A, bool wireframeOnly){
	//buat pixelboolmatrix
	//cari x,y paling besar dan paling kecil
	int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
	for (int i=0;i<size();i++){
		const point& p = at(i);
		if (p.getX()<xmin) xmin=p.getX();
		if (p.getX()>xmax) xmax=p.getX();
		if (p.getY()<ymin) ymin=p.getY();
		if (p.getY()>ymax) ymax=p.getY();
	}
	pixelBoolMatrix mat(xmax-xmin+1,ymax-ymin+1);
	//biar ngga bocor ke negatif
	polygon ptrans = hasilGeser(-xmin, -ymin);

	mat.setAll(false);	
	if (wireframeOnly)
		mat.setWireframe(ptrans,true);
	else
		mat.setSolid(ptrans,true);

	mat.draw(x+xmin,y+ymin,R,G,B,A);
}


