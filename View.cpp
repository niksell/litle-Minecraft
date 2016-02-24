#include "View.h"

View::View(){
	vPress = 0;
}
void View::playerView(float &x, float &y, float &z, float &lx, float &lz){
	x = playerX;
	y = playerY;
	lx = playerLx;
	lz = playerLz;
	z = playerZ;
	vPress = 0;
}
void View::firstView(float &x, float &y, float &z, float &lx, float &lz){
	playerX = x;
	playerY = y;
	playerZ = z;
	playerLx = lx;
	playerLz = lz;
	x = 0.0;
	y = 65.0;
	z = 0.0;
	//lx =-31.0;
	//ly1 = 0.0;
	//lz =-31.0;
	vPress++;
}
void View::secondView(float &x, float &y, float &z, float &lx, float &lz){
	lx = -32.0;
	//	y = 31.0;
	lz = 0.0;
	x = 0.0;
	y = 65.0;
	z = 0.0;
	vPress++;
}
void View::thirdView(float &x, float &y, float &z, float &lx, float &lz){
	lz = -32.0;
	//y = 31.0;
	lx = 0.0;
	x = 0.0;
	y = 65.0;
	z = 0.0;
	vPress++;
}
void View::fourthView(float &x, float &y, float &z, float &lx, float &lz){
	lz = 31.0;
	//	y = 31.0;
	lx = 31.0;
	x = 0.0;
	y = 65.0;
	z = 0.0;
	vPress++;
}
void View::addVPress(){
	if (vPress > 3){
		vPress == 0;
	}
	vPress++;
}
int View::getVPress(){
	return vPress;
}



