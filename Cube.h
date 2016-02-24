#ifndef Cube_H
#define Cube_H


#include "Utils.h"
#include "ColorCube.h"

class Cube :public ColorCube{

public:
	Cube();
	void setX(int aX);
	void setZ(int aZ);
	int getX();
	int getZ();
	void setColor(int aColor, int aY);
	int getColor(int i);

private:
	int x, y, z;
	int colors[64];
};


#endif
