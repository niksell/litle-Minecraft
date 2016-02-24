//#include <math.h>
#include "MouseCamera.h"

MouseCamera::MouseCamera(){
	xPrevious = -1;
	yPrevious = -1;
	angle = -0.01f;
	fraction = -0.01f;
}
void MouseCamera::MouseUp(int y, float &ly1){
	ly1 -= ly1 * fraction;
	if (ly1 > 65){
		ly1 = 65;
	}
	yPrevious = y;
}
void MouseCamera::MouseDown(int y, float &ly1){
	ly1 += ly1 * fraction;

	if (ly1 < 1){
		ly1 = 1;
	}
	yPrevious = y;
}
void MouseCamera::MouseRight(int x, float &lx, float &lz){


	angle += 0.01f;
	lx = sin(angle);
	lz = -cos(angle);
	xPrevious = x;


}
void MouseCamera::MouseLeft(int x, float &lx, float &lz){
	angle -= 0.01f;
	lx = sin(angle);
	lz = -cos(angle);
	xPrevious = x;
}
int MouseCamera::getPreviousX(){
	return xPrevious;
}
int MouseCamera::getPreviousY(){
	return yPrevious;
}
float MouseCamera::getAngle(){
	return angle;
}



