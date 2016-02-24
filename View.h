
#ifndef View_H
#define View_H
#include "Utils.h"
class View{
public:
	View();
	void playerView(float &x, float &y, float &z, float &lx, float &lz);
	void firstView(float &x, float &y, float &z, float &lx, float &lz);
	void secondView(float &x, float &y, float &z, float &lx, float &lz);
	void thirdView(float &x, float &y, float &z, float &lx, float &lz);
	void fourthView(float &x, float &y, float &z, float &lx, float &lz);
	void addVPress();
	int getVPress();

private:
	int x, z, vPress, y, lz, lx, playerX, playerY, playerZ, playerLx, playerLz;
};

#endif

