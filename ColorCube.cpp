#include "ColorCube.h"



void ColorCube::drawRedCube(){

	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(1);



}
void ColorCube::drawBlueCube(){

	glColor3f(0.0, 0.0, 1.0);
	glutSolidCube(1);



}
void ColorCube::drawMagentaCube(){

	glColor3f(1.0, 0.0, 1.0);
	glutSolidCube(1);



}
void ColorCube::drawGreenCube(){

	glColor3f(0.0, 1.0, 0.0);
	glutSolidCube(1);



}
void ColorCube::drawYellowCube(){

	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(1);

}


