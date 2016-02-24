
#ifndef MouseCamera_H
#define MouseCamera_H
#include "Utils.h"
class MouseCamera{

public:
	MouseCamera();
	void MouseUp(int y, float &ly1);
	void MouseDown(int y, float &ly1);
	void MouseLeft(int x, float &lx, float &ly);
	void MouseRight(int x, float &lx, float &ly);
	float getAngle();
	int getPreviousX();
	int getPreviousY();



private:
	int xPrevious, yPrevious;
	float angle, fraction;

};


#endif

