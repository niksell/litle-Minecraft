
#ifndef Move_H
#define Move_H

#include "Cube.h"
#include "Utils.h"

class Move{
public:
	Move();
	Move(float aSpeed);
	void moveUp(float &x, float &z, float lx, float lz);
	void moveDown(float &x, float &z, float lx, float lz);
	void moveRight(float &x, float &z, float anAngle);
	void moveLeft(float &x, float &z, float anAngle);
	void checkMove(float &x, float &z);
	bool checkForCube(float x, float y, float z, Cube cubes[64][64], float lx, float lz, char key);

private:
	float speed;

};


#endif

