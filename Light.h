
#ifndef Light_H
#define Light_H
#include "Utils.h"
class Light{
public:
	Light();
	void openLight(int aNumber, float xp, float yp, float zp, float lx, float lz);
	void addLightDuration();
	void drawLightSphere();
	int getLightNumber();
	int getLightDuration();
	bool getOn();

private:
	bool on;
	int lightNumber, ligthDuration, xx, yy, zz;
};


#endif

