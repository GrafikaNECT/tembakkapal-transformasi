#include "kapallaut.h"
#include "printchar.h"

kapallaut::kapallaut(int _x,int _y){
	x=_x;
	y=_y;
	draw(x,y);
}

kapallaut::kapallaut(int _x,int _y,int _width,int _height){
	x=_x;
	y=_y;
	width=_width;
	height=_height;
}

/*bullet kapallaut::shootBullet(int x){
	
}
*/
void kapallaut::draw(int x, int y){
	drawPicture(x,y,15,200,"ship.txt");
}

void kapallaut::move(int deltax,int deltay){

}
