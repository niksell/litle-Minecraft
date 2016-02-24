
#ifndef Player_H
#define Player_H

#include "Utils.h"
#include "Cube.h"
class Player{
public:
	Player();
	void checkForPoints(float &x, float &y, float &z, Cube cubes[64][64], float lx, float &ly, float lz, char key);
	void destroyCube(float x, int y, float z, float lx, float lz, Cube cubes[64][64]);
	bool destroyAllCubes(float x, float z, float lx, float lz, Cube cubes[64][64]);
	void addCube(float x, int y, float z, float lx, float lz, Cube cubes[64][64]);
	void kickCube(float x, int y, float z, float lx, float lz, Cube cubes[64][64]);
	void dropCube(Cube cubes[64][64]);
	void addCubeStock(int aCubeStock);
	void removeCubeStock();
	int getPoints();
	int getCubeStock();

private:
	int points, cubeStock;
};

#endif


