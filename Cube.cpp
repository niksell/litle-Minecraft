

#include "Cube.h"



Cube::Cube(){
	for (int i = 0; i < 64; i++){
		colors[i] = 0;
	}
}
void Cube::setX(int aX){
	x = aX;
}
void Cube::setZ(int aZ){
	z = aZ;
}
int Cube::getX(){
	return x;
}
int Cube::getZ(){
	return z;
}
void Cube::setColor(int aColor, int aY){
	colors[aY] = aColor;
}
int Cube::getColor(int i){
	return (colors[i]);
}


