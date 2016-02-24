#define _CRT_SECURE_NO_WARNINGS

/*#include <iostream>
//#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Gl/glut.h>*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <math.h>

using namespace std;

#define BLUE		1
#define YELLOW		2
#define RED			3
#define GREEN		4
#define MAGENTA		5
#define ESC			27
#define SPACEBAR	32

GLfloat whiteSpecularLight[] = { 1.0, 1.0, 1.0 }; //set the light specular to white
GLfloat blackAmbientLight[] = { 0.0, 0.0, 0.0 }; //set the light ambient to black
GLfloat whiteDiffuseLight[] = { 1.0, 1.0, 1.0 }; //set the diffuse light to white
GLfloat blankMaterial[] = { 0.0, 0.0, 0.0 }; //set the diffuse light to white
GLfloat mShininess[] = { 128 }; //set the shininess of the material


class Display{

public:
	void displayPoints(const char *text, int length);
	void displayCubeStock(const char *text, int length);


};
void Display::displayPoints(const char *text, int length){
	glColor3f(0, 1, 0);
	glMatrixMode(GL_PROJECTION); // change the current matrix to PROJECTION
	double matrix[16]; // 16 doubles in stack memory
	glGetDoublev(GL_PROJECTION_MATRIX, matrix); // get the values from PROJECTION matrix to local variable
	glLoadIdentity(); // reset PROJECTION matrix to identity matrix
	glOrtho(0, 800, 0, 100, -5, 5); // orthographic perspective

	glMatrixMode(GL_MODELVIEW); // change current matrix to MODELVIEW matrix again
	glLoadIdentity(); // reset it to identity matrix
	glPushMatrix(); // push current state of MODELVIEW matrix to stack
	glLoadIdentity(); // reset it again. (may not be required, but it my convention)
	glRasterPos2i(30, 95); // raster position in 2D
	for (int i = 0; i<length; i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]); // generation of characters in our text with 9 by 15 GLU font
	}
	glPopMatrix(); // get MODELVIEW matrix value from stack
	glMatrixMode(GL_PROJECTION); // change current matrix mode to PROJECTION
	glLoadMatrixd(matrix); // reset
	glMatrixMode(GL_MODELVIEW); // change current matrix mode to MODELVIEW
	glFlush();
	glutSwapBuffers();
}
void Display::displayCubeStock(const char *text, int length){
	glColor3f(0, 1, 0);
	glMatrixMode(GL_PROJECTION); // change the current matrix to PROJECTION
	double matrix[16]; // 16 doubles in stack memory
	glGetDoublev(GL_PROJECTION_MATRIX, matrix); // get the values from PROJECTION matrix to local variable
	glLoadIdentity(); // reset PROJECTION matrix to identity matrix
	glOrtho(0, 800, 0, 100, -5, 5); // orthographic perspective

	glMatrixMode(GL_MODELVIEW); // change current matrix to MODELVIEW matrix again
	glLoadIdentity(); // reset it to identity matrix
	glPushMatrix(); // push current state of MODELVIEW matrix to stack
	glLoadIdentity(); // reset it again. (may not be required, but it my convention)
	glRasterPos2i(30, 90); // raster position in 2D
	for (int i = 0; i<length; i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]); // generation of characters in our text with 9 by 15 GLU font
	}
	glPopMatrix(); // get MODELVIEW matrix value from stack
	glMatrixMode(GL_PROJECTION); // change current matrix mode to PROJECTION
	glLoadMatrixd(matrix); // reset
	glMatrixMode(GL_MODELVIEW); // change current matrix mode to MODELVIEW
	glFlush();
	glutSwapBuffers();
}

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

class ColorCube{
public:

	void drawRedCube();
	void drawBlueCube();
	void drawMagentaCube();
	void drawGreenCube();
	void drawYellowCube();

};
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
Move::Move(){
	speed = 0.1f;
}
void Move::moveUp(float &x, float &z, float lx, float lz){
	x += lx * speed;
	z += lz * speed;
}
void Move::moveDown(float &x, float &z, float lx, float lz){
	x -= lx * speed;
	z -= lz * speed;
}
void Move::moveRight(float &x, float &z, float anAngle){

	x += speed*cos(anAngle);
	z += speed*sin(anAngle);

}
void Move::moveLeft(float &x, float &z, float anAngle){

	x -= speed*cos(anAngle);
	z -= speed*sin(anAngle);

}
void Move::checkMove(float &x, float &z){

	if (round(z) >= 31){
		z = round(z) - 1;
	}
	else if (round(x) >= 31){

		x = round(x) - 1;
	}
	else if (round(z) < -32){

		z = round(z) + 1;
	}
	else if (round(x) < -31){

		x = round(x) + 1;

	}


}
bool Move::checkForCube(float x, float y, float z, Cube cubes[64][64], float lx, float lz, char key){

	bool isOk = true;
	int lx1 = round(lx);
	int lz1 = round(lz);
	int x1 = round(x) + 32;
	int z1 = round(z) + 32;

	if (lx1 == 0 && lz1 == -1){

		if (((cubes[x1][z1 - 1].getColor(y + 1) != 0 && cubes[x1][z1 - 1].getColor(y) != 0) || (cubes[x1][z1 - 1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'w' || key == 'W')){
			if (cubes[x1][z1 - 1].getColor(0) != 0){


				isOk = false;
			}

		}
		else if (((cubes[x1][z1 + 1].getColor(y + 1) != 0 && cubes[x1][z1 + 1].getColor(y) != 0) || (cubes[x1][z1 + 1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 's' || key == 'S')){
			isOk = false;
		}
		else if (((cubes[x1 - 1][z1].getColor(y + 1) != 0 && cubes[x1 - 1][z1].getColor(y) != 0) || (cubes[x1 - 1][z1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'a' || key == 'A')){
			isOk = false;
		}
		else if (((cubes[x1 + 1][z1].getColor(y + 1) != 0 && cubes[x1 + 1][z1].getColor(y) != 0) || (cubes[x1 + 1][z1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'd' || key == 'D')){
			isOk = false;
		}
	}
	else if (lx1 == 1 && lz1 == 0){

		if (((cubes[x1][z1 + 1].getColor(y + 1) != 0 && cubes[x1][z1 + 1].getColor(y) != 0) || (cubes[x1][z1 + 1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'd' || key == 'D')){

			isOk = false;

		}
		else if (((cubes[x1 - 1][z1].getColor(y + 1) != 0 && cubes[x1 - 1][z1].getColor(y) != 0) || (cubes[x1 - 1][z1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 's' || key == 'S')){
			isOk = false;
		}
		else if (((cubes[x1][z1 - 1].getColor(y + 1) != 0 && cubes[x1][z1 - 1].getColor(y) != 0) || (cubes[x1][z1 - 1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'a' || key == 'A')){
			isOk = false;
		}
		else if (((cubes[x1 + 1][z1].getColor(y + 1) != 0 && cubes[x1 + 1][z1].getColor(y) != 0) || (cubes[x1 + 1][z1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'W' || key == 'w')){

			isOk = false;
		}
	}
	else if (round(lx) == 0 && round(lz) == 1){



		if (((cubes[x1][z1 + 1].getColor(y + 1) != 0 && cubes[x1][z1 + 1].getColor(y) != 0) || (cubes[x1][z1 + 1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'w' || key == 'W')){

			isOk = false;

		}
		else if (((cubes[x1][z1 - 1].getColor(y + 1) != 0 && cubes[x1][z1 - 1].getColor(y) != 0) || (cubes[x1][z1 - 1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 's' || key == 'S')){
			isOk = false;
		}
		else if (((cubes[x1 + 1][z1].getColor(y + 1) != 0 && cubes[x1 + 1][z1].getColor(y) != 0) || (cubes[x1 + 1][z1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'a' || key == 'A')){
			isOk = false;
		}
		else if (((cubes[x1 - 1][z1].getColor(y + 1) != 0 && cubes[x1 - 1][z1].getColor(y) != 0) || (cubes[x1 - 1][z1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'd' || key == 'D')){
			isOk = false;
		}
	}
	else if (round(lx) == -1 && round(lz) == 0){

		if (((cubes[x1][z1 - 1].getColor(y + 1) != 0 && cubes[x1][z1 - 1].getColor(y) != 0) || (cubes[x1][z1 - 1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'd' || key == 'D')){

			isOk = false;

		}
		else if (((cubes[x1 + 1][z1].getColor(y + 1) != 0 && cubes[x1 + 1][z1].getColor(y) != 0) || (cubes[x1 + 1][z1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 's' || key == 'S')){
			isOk = false;
		}
		else if (((cubes[x1][z1 + 1].getColor(y + 1) != 0 && cubes[x1][z1 + 1].getColor(y) != 0) || (cubes[x1][z1 + 1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'a' || key == 'A')){
			isOk = false;
		}
		else if (((cubes[x1 - 1][z1].getColor(y + 1) != 0 && cubes[x1 - 1][z1].getColor(y) != 0) || (cubes[x1 - 1][z1].getColor(y) != 0 && cubes[x1][z1].getColor(y + 1) != 0)) && (key == 'W' || key == 'w')){
			isOk = false;
		}
	}
	return isOk;
}

class Player{
public:
	Player();
	void checkForPoints(float &x, float &y, float &z, Cube cubes[64][64], float lx, float &ly, float lz, char key);
	void destroyCube(float x, int y, float z, float lx, float lz, Cube cubes[64][64]);
	void destroyAllCubes(float x, float z, float lx, float lz, Cube cubes[64][64]);
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
Player::Player(){
	points = 50;
	cubeStock = 0;
}
void Player::addCube(float x, int y, float z, float lx, float lz, Cube cubes[64][64]){
	if (round(lx) == 0 && round(lz) == -1){

		int i1 = round(x) + 32;
		int i2 = round(z) + 32 - 1;
		int color = rand() % 4 + 1;

		if (i2 >= 0){
			if (cubes[i1][i2].getColor(y) == 0){

				cubes[i1][i2].setColor(color, y);

			}
			else if (cubes[i1][i2].getColor(y) != 0){
				bool b = false;
				for (int i = y; i < 64; i++){
					if (cubes[i1][i2].getColor(i) == 0 && b == false){
						cubes[i1][i2].setColor(color, i);
						b = true;

					}
				}
			}
		}
	}
	else if (round(lx) == 1 && round(lz) == 0){

		int i1 = round(x + 1) + 32;
		int i2 = round(z) + 32;
		int color = rand() % 4 + 1;

		if (i1 <64){
			if (cubes[i1][i2].getColor(y) == 0){

				cubes[i1][i2].setColor(color, y);

			}
			else if (cubes[i1][i2].getColor(y) != 0){
				bool b = false;
				for (int i = y; i < 64; i++){
					if (cubes[i1][i2].getColor(i) == 0 && b == false){
						cubes[i1][i2].setColor(color, i);
						b = true;

					}
				}
			}
		}

	}
	else if (round(lx) == 0 && round(lz) == 1){

		int i1 = round(x) + 32;
		int i2 = round(z + 1) + 32;
		int color = rand() % 4 + 1;

		if (i2 <64){
			if (cubes[i1][i2].getColor(y) == 0){

				cubes[i1][i2].setColor(color, y);

			}
			else if (cubes[i1][i2].getColor(y) != 0){
				bool b = false;
				for (int i = y; i < 64; i++){
					if (cubes[i1][i2].getColor(i) == 0 && b == false){
						cubes[i1][i2].setColor(color, i);
						b = true;

					}
				}
			}
		}


	}
	else if (round(lx) == -1 && round(lz) == 0){

		int i1 = round(x) + 32 - 1;
		int i2 = round(z) + 32;
		int color = rand() % 4 + 1;

		if (i1 >= 0){
			if (cubes[i1][i2].getColor(y) == 0){

				cubes[i1][i2].setColor(color, y);

			}
			else if (cubes[i1][i2].getColor(y) != 0){
				bool b = false;
				for (int i = y; i < 64; i++){
					if (cubes[i1][i2].getColor(i) == 0 && b == false){
						cubes[i1][i2].setColor(color, i);
						b = true;

					}
				}
			}
		}
	}
	points += 5;
}
void Player::destroyCube(float x, int y, float z, float lx, float lz, Cube cubes[64][64]){
	if (round(lx) == 0 && round(lz) == -1){

		int i1 = round(x) + 32;
		int i2 = round(z - 1) + 32;
		cubes[i1][i2].setColor(0, y);

	}
	else if (round(lx) == 1 && round(lz) == 0){

		int i1 = round(x + 1) + 32;
		int i2 = round(z) + 32;
		cubes[i1][i2].setColor(0, y);

	}
	else if (round(lx) == 0 && round(lz) == 1){

		int i1 = round(x) + 32;
		int i2 = round(z + 1) + 32;
		cubes[i1][i2].setColor(0, y);
	}
	else if (round(lx) == -1 && round(lz) == 0){

		int i1 = round(x - 1) + 32;
		int i2 = round(z) + 32;
		cubes[i1][i2].setColor(0, y);
	}
}
void Player::destroyAllCubes(float x, float z, float lx, float lz, Cube cubes[64][64]){

	if (round(lx) == 0 && round(lz) == -1){

		int i1 = round(x) + 32;
		int i2 = round(z) + 32 - 1;
		for (int k = 0; k <64; k++){
			if (cubes[i1][i2].getColor(k) != MAGENTA){
				cubes[i1][i2].setColor(0, k);
			}

		}

	}
	else if (round(lx) == 1 && round(lz) == 0){
		int i1 = round(x) + 32 + 1;
		int i2 = round(z) + 32;
		for (int k = 0; k <64; k++){
			if (cubes[i1][i2].getColor(k) != MAGENTA){
				cubes[i1][i2].setColor(0, k);
			}
		}

	}
	else if (round(lx) == 0 && round(lz) == 1){
		int i1 = round(x) + 32;
		int i2 = round(z) + 32 + 1;
		for (int k = 0; k <64; k++){
			if (cubes[i1][i2].getColor(k) != MAGENTA){
				cubes[i1][i2].setColor(0, k);
			}

		}

	}
	else if (round(lx) == -1 && round(lz) == 0){
		int i1 = round(x) + 32 - 1;
		int i2 = round(z) + 32;
		for (int k = 0; k <64; k++){
			if (cubes[i1][i2].getColor(k) != MAGENTA){
				cubes[i1][i2].setColor(0, k);
			}

		}
	}

	points -= 5;

}
void Player::dropCube(Cube cubes[64][64]){
	bool winPoints = false;
	for (int i = 0; i < 64; i++){
		for (int j = 0; j < 64; j++){
			for (int k = 1; k <63; k++){
				if (cubes[i][j].getColor(k) == 0){
					int kHelp = k + 1;
					while (kHelp <64 && cubes[i][j].getColor(k) == 0){
						if (cubes[i][j].getColor(kHelp) != 0){
							winPoints = true;
							int color = cubes[i][j].getColor(kHelp);
							cubes[i][j].setColor(color, k);
							cubes[i][j].setColor(0, kHelp);
						}
						kHelp++;
					}
				}
			}
		}
	}
	if (winPoints){
		points += 50;
	}
}
void Player::checkForPoints(float &x, float &y, float &z, Cube cubes[64][64], float lx, float &ly, float lz, char key){
	int lx1 = round(lx);
	int lz1 = round(lz);
	int x1 = round(x) + 32;
	int z1 = round(z) + 32;
	int frontCubeY = 0;
	int backCubeY = 0;
	int leftCubeY = 0;
	int rightCubeY = 0;
	int magentaCubeY = 0;

	for (int i = 0; i <64; i++){
		if (cubes[x1][z1 - 1].getColor(i) != 0){
			frontCubeY = i + 1;
		}
		if (cubes[x1][z1 + 1].getColor(i) != 0){
			backCubeY = i + 1;
		}
		if (cubes[x1 - 1][z1].getColor(i) != 0){
			leftCubeY = i + 1;
		}
		if (cubes[x1 + 1][z1].getColor(i) != 0){
			rightCubeY = i + 1;
		}
		if (cubes[32][32].getColor(i) != 0){
			magentaCubeY++;
		}

	}



	if (lx1 == 0 && lz1 == -1){

		if ((key == 'w' || key == 'W') && cubes[x1][z1 - 1].getColor(y) != 0){
			y++;
			z = (float)round(z) - 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'w' || key == 'W') && cubes[x1][z1 - 1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'w' || key == 'W') && cubes[x1][z1 - 1].getColor(y) == 0 && cubes[x1][z1 - 1].getColor(y - 1) == 0){

			points -= (y - frontCubeY - 1) * 5;
			y = frontCubeY;
			z = (float)round(z) - 1;
			ly = y;



		}
		else if ((key == 's' || key == 'S') && cubes[x1][z1 + 1].getColor(y) != 0){
			y++;
			z = (float)round(z) + 1;
			ly = y;
			points += 5;
		}
		else if ((key == 's' || key == 'S') && cubes[x1][z1 + 1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'S' || key == 's') && cubes[x1][z1 + 1].getColor(y) == 0 && cubes[x1][z1 + 1].getColor(y - 1) == 0){


			points -= (y - backCubeY - 1) * 5;
			y = backCubeY;
			z = (float)round(z) + 1;
			ly = y;
		}
		else if ((key == 'a' || key == 'A') && cubes[x1 - 1][z1].getColor(y) != 0){
			y++;
			x = (float)round(x) - 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'a' || key == 'A') && cubes[x1 - 1][z1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'a' || key == 'A') && cubes[x1 - 1][z1].getColor(y) == 0 && cubes[x1 - 1][z1].getColor(y - 1) == 0){

			cout << "backCubeY = " << leftCubeY << endl;
			points -= (y - leftCubeY - 1) * 5;
			y = leftCubeY;
			x = (float)round(x) - 1;
			ly = y;
		}

		else if ((key == 'd' || key == 'D') && cubes[x1 + 1][z1].getColor(y) != 0){
			y++;
			x = (float)round(x) + 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'd' || key == 'D') && cubes[x1 + 1][z1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'd' || key == 'D') && cubes[x1 + 1][z1].getColor(y) == 0 && cubes[x1 + 1][z1].getColor(y - 1) == 0){


			points -= (y - rightCubeY - 1) * 5;
			y = rightCubeY;
			x = (float)round(x) + 1;
			ly = y;
		}



	}
	else if (round(lx) == 1 && round(lz) == 0){

		if ((key == 'a' || key == 'A') && cubes[x1][z1 - 1].getColor(y) != 0){
			y++;
			z = (float)round(z) - 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'a' || key == 'A') && cubes[x1][z1 - 1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'a' || key == 'A') && cubes[x1][z1 - 1].getColor(y) == 0 && cubes[x1][z1 - 1].getColor(y - 1) == 0){

			points -= (y - frontCubeY - 1) * 5;
			y = frontCubeY;
			z = (float)round(z) - 1;
			ly = y;



		}
		else if ((key == 'd' || key == 'D') && cubes[x1][z1 + 1].getColor(y) != 0){
			y++;
			z = (float)round(z) + 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'd' || key == 'D') && cubes[x1][z1 + 1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'd' || key == 'D') && cubes[x1][z1 + 1].getColor(y) == 0 && cubes[x1][z1 + 1].getColor(y - 1) == 0){


			points -= (y - backCubeY - 1) * 5;
			y = backCubeY;
			z = (float)round(z) + 1;
			ly = y;
		}
		else if ((key == 's' || key == 'S') && cubes[x1 - 1][z1].getColor(y) != 0){
			y++;
			x = (float)round(x) - 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'S' || key == 's') && cubes[x1 - 1][z1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 's' || key == 'S') && cubes[x1 - 1][z1].getColor(y) == 0 && cubes[x1 - 1][z1].getColor(y - 1) == 0){


			points -= (y - leftCubeY - 1) * 5;
			y = leftCubeY;
			x = (float)round(x) - 1;
			ly = y;
		}

		else if ((key == 'W' || key == 'w') && cubes[x1 + 1][z1].getColor(y) != 0){
			y++;
			x = (float)round(x) + 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'W' || key == 'w') && cubes[x1 + 1][z1].getColor(0) == 0 && y == 1){
			cout << "x+1 = " << x1 + 1 << endl;;
			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'W' || key == 'w') && cubes[x1 + 1][z1].getColor(y) == 0 && cubes[x1 + 1][z1].getColor(y - 1) == 0){


			points -= (y - rightCubeY - 1) * 5;
			y = rightCubeY;
			x = (float)round(x) + 1;
			ly = y;
		}




	}
	else if (round(lx) == 0 && round(lz) == 1){

		if ((key == 's' || key == 'S') && cubes[x1][z1 - 1].getColor(y) != 0){
			y++;
			z = (float)round(z) - 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'S' || key == 's') && cubes[x1][z1 - 1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 's' || key == 'S') && cubes[x1][z1 - 1].getColor(y) == 0 && cubes[x1][z1 - 1].getColor(y - 1) == 0){

			points -= (y - frontCubeY - 1) * 5;
			y = frontCubeY;
			z = (float)round(z) - 1;
			ly = y;



		}
		else if ((key == 'W' || key == 'w') && cubes[x1][z1 + 1].getColor(y) != 0){
			y++;
			z = (float)round(z) + 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'w' || key == 'W') && cubes[x1][z1 + 1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'w' || key == 'W') && cubes[x1][z1 + 1].getColor(y) == 0 && cubes[x1][z1 + 1].getColor(y - 1) == 0){


			points -= (y - backCubeY - 1) * 5;
			y = backCubeY;
			z = (float)round(z) + 1;
			ly = y;
		}
		else if ((key == 'd' || key == 'D') && cubes[x1 - 1][z1].getColor(y) != 0){
			y++;
			x = (float)round(x) - 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'D' || key == 'd') && cubes[x1 - 1][z1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'd' || key == 'D') && cubes[x1 - 1][z1].getColor(y) == 0 && cubes[x1 - 1][z1].getColor(y - 1) == 0){


			points -= (y - leftCubeY - 1) * 5;
			y = leftCubeY;
			x = (float)round(x) - 1;
			ly = y;
		}

		else if ((key == 'A' || key == 'a') && cubes[x1 + 1][z1].getColor(y) != 0){
			y++;
			x = (float)round(x) + 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'A' || key == 'a') && cubes[x1 + 1][z1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'A' || key == 'a') && cubes[x1 + 1][z1].getColor(y) == 0 && cubes[x1 + 1][z1].getColor(y - 1) == 0){


			points -= (y - rightCubeY - 1) * 5;
			y = rightCubeY;
			x = (float)round(x) + 1;
			ly = y;
		}



	}
	else if (round(lx) == -1 && round(lz) == 0){

		if ((key == 'd' || key == 'D') && cubes[x1][z1 - 1].getColor(y) != 0){
			y++;
			z = (float)round(z) - 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'd' || key == 'D') && cubes[x1][z1 - 1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'd' || key == 'D') && cubes[x1][z1 - 1].getColor(y) == 0 && cubes[x1][z1 - 1].getColor(y - 1) == 0){

			points -= (y - frontCubeY - 1) * 5;
			y = frontCubeY;
			z = (float)round(z) - 1;
			ly = y;



		}
		else if ((key == 'A' || key == 'a') && cubes[x1][z1 + 1].getColor(y) != 0){
			y++;
			z = (float)round(z) + 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'a' || key == 'A') && cubes[x1][z1 + 1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'a' || key == 'A') && cubes[x1][z1 + 1].getColor(y) == 0 && cubes[x1][z1 + 1].getColor(y - 1) == 0){


			points -= (y - backCubeY - 1) * 5;
			y = backCubeY;
			z = (float)round(z) + 1;
			ly = y;
		}
		else if ((key == 'w' || key == 'W') && cubes[x1 - 1][z1].getColor(y) != 0){
			y++;
			x = (float)round(x) - 1;
			ly = y;
			points += 5;
		}
		else if ((key == 'W' || key == 'w') && cubes[x1 - 1][z1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'w' || key == 'W') && cubes[x1 - 1][z1].getColor(y) == 0 && cubes[x1 - 1][z1].getColor(y - 1) == 0){


			points -= (y - leftCubeY - 1) * 5;
			y = leftCubeY;
			x = (float)round(x) - 1;
			ly = y;
		}

		else if ((key == 'S' || key == 's') && cubes[x1 + 1][z1].getColor(y) != 0){
			y++;
			x = (float)round(x) + 1;
			ly = y;
			points += 5;
		}
		else if ((key == 's' || key == 'S') && cubes[x1 + 1][z1].getColor(0) == 0 && y == 1){

			x = 0.0;
			z = 0.0;
			y = magentaCubeY;
			ly = y;
			points -= 20;
		}
		else if ((key == 'S' || key == 's') && cubes[x1 + 1][z1].getColor(y) == 0 && cubes[x1 + 1][z1].getColor(y - 1) == 0){


			points -= (y - rightCubeY - 1) * 5;
			y = rightCubeY;
			x = (float)round(x) + 1;
			ly = y;
		}

	}

}
void Player::kickCube(float x, int y, float z, float lx, float lz, Cube cubes[64][64]){
	bool nextCube = false;
	int colorNext = 0;

	if (round(lx) == 0 && round(lz) == -1){
		int x1 = round(x) + 32;
		int z1 = round(z) + 32 - 1;

		if (cubes[x1][z1 - 1].getColor(y) != 0){

			nextCube = true;
			colorNext = cubes[x1][z1].getColor(y);
			cubes[x1][z1].setColor(0, y);
			z1--;


		}


		if (nextCube == false){
			if (cubes[x1][z1].getColor(y) != 0){
				int z2 = cubes[x1][z1].getZ();
				int color = cubes[x1][z1].getColor(y);
				if (z2 - 1 >= -32){
					cubes[x1][z1].setColor(0, y);
					cubes[x1][z1 - 1].setColor(color, y);

				}
				else{

					cubes[x1][z1].setColor(0, y);

				}
			}
		}

		else if (nextCube == true){
			int i = z1;
			while (nextCube){
				int color = colorNext;

				colorNext = cubes[x1][i].getColor(y);
				cubes[x1][i].setColor(color, y);
				if (cubes[x1][i - 1].getColor(y) != 0){
					nextCube = true;


				}
				else{

					nextCube = false;
					cubes[x1][i - 1].setColor(colorNext, y);

				}
				i--;
				int z2 = cubes[x1][i + 1].getZ();

				if (z2 - 1 < -32){

					cubes[x1][i].setColor(0, y);
				}


			}
		}
	}
	else if (round(lx) == 1 && round(lz) == 0){

		int x1 = round(x) + 32 + 1;
		int z1 = round(z) + 32;

		if (cubes[x1 + 1][z1].getColor(y) != 0){
			nextCube = true;
			colorNext = cubes[x1][z1].getColor(y);
			cubes[x1][z1].setColor(0, y);
			x1++;


		}


		if (nextCube == false){
			if (cubes[x1][z1].getColor(y) != 0){
				int z2 = cubes[x1][z1].getX();
				int color = cubes[x1][z1].getColor(y);
				if (z2 + 1 < 32){
					cubes[x1][z1].setColor(0, y);
					cubes[x1 + 1][z1].setColor(color, y);

				}
				else{

					cubes[x1][z1].setColor(0, y);

				}
			}
		}

		else if (nextCube == true){
			int i = x1;
			while (nextCube){
				int color = colorNext;

				colorNext = cubes[i][z1].getColor(y);
				cubes[i][z1].setColor(color, y);
				if (cubes[i + 1][z1].getColor(y) != 0){
					nextCube = true;



				}
				else{

					nextCube = false;
					cubes[i + 1][z1].setColor(colorNext, y);


				}
				i++;
				int z2 = cubes[i + 1][z1].getX();

				if (z2 + 1 >= 32){

					cubes[i][z1].setColor(0, y);
				}


			}
		}

	}
	else if (round(lx) == 0 && round(lz) == 1){

		int x1 = round(x) + 32;
		int z1 = round(z) + 32 + 1;

		if (cubes[x1][z1 + 1].getColor(y) != 0){
			nextCube = true;
			colorNext = cubes[x1][z1].getColor(y);
			cubes[x1][z1].setColor(0, y);
			z1++;


		}


		if (nextCube == false){
			if (cubes[x1][z1].getColor(y) != 0){
				int z2 = cubes[x1][z1].getZ();
				int color = cubes[x1][z1].getColor(y);
				if (z2 + 1 < 32){
					cubes[x1][z1].setColor(0, y);
					cubes[x1][z1 + 1].setColor(color, y);

				}
				else{

					cubes[x1][z1].setColor(0, y);

				}
			}
		}

		else if (nextCube == true){
			int i = z1;
			while (nextCube){
				int color = colorNext;

				colorNext = cubes[x1][i].getColor(y);
				cubes[x1][i].setColor(color, y);
				if (cubes[x1][i + 1].getColor(y) != 0){
					nextCube = true;
				}
				else{

					nextCube = false;
					cubes[x1][i + 1].setColor(colorNext, y);


				}
				i++;
				int z2 = cubes[x1][i - 1].getZ();
				if (z2 + 1 >= 32){
					cubes[x1][i].setColor(0, y);
				}

			}
		}

	}
	else if (round(lx) == -1 && round(lz) == 0){


		int x1 = round(x) + 32 - 1;
		int z1 = round(z) + 32;
		if (x1 > 0){
			if (cubes[x1 - 1][z1].getColor(y) != 0){
				nextCube = true;
				colorNext = cubes[x1][z1].getColor(y);
				cubes[x1][z1].setColor(0, y);
				x1--;
			}
		}


		if (nextCube == false){
			if (cubes[x1][z1].getColor(y) != 0){
				int z2 = cubes[x1][z1].getX();
				int color = cubes[x1][z1].getColor(y);
				if (z2 - 1 >= -32){
					cubes[x1][z1].setColor(0, y);
					cubes[x1 - 1][z1].setColor(color, y);
				}
				else{

					cubes[x1][z1].setColor(0, y);

				}
			}
		}

		else if (nextCube == true){
			int i = x1;
			while (nextCube&&i>0){
				int color = colorNext;

				colorNext = cubes[i][z1].getColor(y);
				cubes[i][z1].setColor(color, y);
				if (cubes[i - 1][z1].getColor(y) != 0){
					nextCube = true;

				}
				else{

					nextCube = false;
					cubes[i - 1][z1].setColor(colorNext, y);

				}
				i--;
				int z2 = cubes[i + 1][z1].getX();
				if (z2 - 1 < -32){

					cubes[i][z1].setColor(0, y);
				}

			}
		}

	}





}
void Player::addCubeStock(int aCubeStock){
	cubeStock += aCubeStock;
	//cubeStock = aCubeStock;
}
void Player::removeCubeStock(){
	cubeStock--;
	if (cubeStock < 0){
		cubeStock = 0;
	}
}
int Player::getPoints(){
	return points;
}
int Player::getCubeStock(){
	return cubeStock;
}

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
Light::Light(){
	on = false;
	ligthDuration = 0;
}
void Light::addLightDuration(){
	ligthDuration++;
}
void Light::openLight(int aNumber, float xp, float yp, float zp, float lx, float lz){
	lightNumber = aNumber;
	on = true;


	if (round(lx) == 0 && round(lz) == -1){

		xx = round(xp);
		zz = round(zp) - 1;

	}
	else if (round(lx) == 1 && round(lz) == 0){

		xx = round(xp) + 1;
		zz = round(zp);


	}
	else if (round(lx) == 0 && round(lz) == 1){

		xx = round(xp);
		zz = round(zp) + 1;

	}
	else if (round(lx) == -1 && round(lz) == 0){

		xx = round(xp) - 1;
		zz = round(zp);

	}
	yy = yp;




}
void Light::drawLightSphere(){

	GLfloat  specular[] = { 1.0f, 1.0f, 1.0f };
	GLfloat  ambientLight[] = { 1.0f, 0.0f, 0.0f };
	GLfloat light_diffuse[] = { 1.0, 0.0, 0.0 };
	GLfloat light1_ambient[] = { 1.0, 0.0, 0.0 };
	GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0 };
	GLfloat  specref[] = { xx, yy, zz, 1.0 };
	GLfloat positio[] = { xx, yy, zz, 1.0 };
	GLfloat spositio[] = { xx, yy, zz, 1.0 };
	GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f };

	glEnable(lightNumber);
	glLightfv(lightNumber, GL_DIFFUSE, lightColor1);
	glLightfv(lightNumber, GL_SPECULAR, whiteSpecularLight);
	glLightfv(lightNumber, GL_AMBIENT, light1_ambient);
	glLightfv(lightNumber, GL_POSITION, positio);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);



	glLightf(lightNumber, GL_SPOT_CUTOFF, 180.0f);
	glLightfv(lightNumber, GL_SPOT_DIRECTION, spositio);
	glLightf(lightNumber, GL_SPOT_EXPONENT, 10.0f);

	glLightf(lightNumber, GL_CONSTANT_ATTENUATION, 0.0f);
	glLightf(lightNumber, GL_LINEAR_ATTENUATION, 0.5f);
	glLightf(lightNumber, GL_QUADRATIC_ATTENUATION, 0.0f);

	glColor3f(1.0, 0.5, 0.0);
	glPushMatrix();
	glTranslatef(xx, yy, zz);
	glutSolidSphere(.50, 20, 20);
	glPopMatrix();
	glFlush();

}
int Light::getLightNumber(){
	return lightNumber;
}
bool Light::getOn(){
	return on;
}
int Light::getLightDuration(){
	return ligthDuration;
}


MouseCamera m;
Cube cubes[64][64];
Move mo;
Player player;
Display display;
View view;
vector<Light> lights;
Light p;
string *pointText;
string *cubeStockText;
int lightNumbers[] = { GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7 };
int freeLight[7];
int sun = -32;
bool sunLight = true; //if sun is not go down
bool lightBall = false; //if there is at least a lightSphere


// actual vector representing the camera's direction
float lx = 0.0f, lz = 1.0f, ly1 = 1.0f;
// XZ position of the camera
float x = 0.0f, z = 0.0f, y = 1.0f;

void initNumbers(){

	for (int i = 0; i < 64; i++){
		for (int j = 0; j < 64; j++){
			cubes[i][j].setX(i - 32);
			if (i != 32 || j != 32){

				int color = rand() % 4 + 1;
				cubes[i][j].setColor(color, 0);
				cubes[i][j].setZ(j - 32);

			}
			else if (i == 32 && j == 32){

				cubes[i][j].setZ(j - 32);

				cubes[i][j].setColor(MAGENTA, 0);

			}

		}

	}

}
void createPointString(){

	char buffer[10];
	char tab[10];
	//itoa(player.getPoints(), buffer, 10);
	sprintf(buffer,"%d",player.getPoints());
	//player.getPoints()=sprintf(buffer."%d",10);
	char p[100];
	strcpy(p, "points");
	strcat(p, " ");
	strcat(p, buffer);
	pointText = new string(p);

}
void createCubeStockString(){

	char buffer[10];
	char p[100];
	//itoa(player.getCubeStock(), buffer, 10);
	sprintf(buffer,"%d",player.getCubeStock());
	strcpy(p, "cube stock is ");
	strcat(p, buffer);
	cubeStockText = new string(p);

}
void mouseCamera(int xx, int yy){


	if (xx < m.getPreviousX()){
		if (xx <= 100){
			glutWarpPointer(200, 200);
			m.MouseLeft(xx, lx, lz);

		}

		m.MouseLeft(xx, lx, lz);

	}
	else if (xx > m.getPreviousX()){
		if (xx >= 400){
			glutWarpPointer(300, 300);
			m.MouseRight(xx, lx, lz);

		}

		m.MouseRight(xx, lx, lz);

	}
	if (yy < m.getPreviousY()){

		if (yy <= 100){
			glutWarpPointer(200, 200);
			m.MouseDown(yy, ly1);

		}
		m.MouseDown(yy, ly1);
	}
	else if (yy > m.getPreviousY()){

		if (yy >= 400){

			glutWarpPointer(300, 300);
			m.MouseUp(yy, ly1);

		}

		m.MouseUp(yy, ly1);
	}

}
void drawLightsSpheres(){

	if (lights.empty() == false){

		for (int i = 0; i < lights.size(); i++){


			if (lights[i].getOn() == true){

				lights[i].drawLightSphere();

			}

		}


	}
	glutSwapBuffers();
}
void drawScence(){

	for (int i = 0; i < 64; i++){

		for (int j = 0; j < 64; j++){

			for (int k = 0; k < 64; k++){

				glPushMatrix();

				if (cubes[i][j].getColor(k) == RED){
					glTranslatef(cubes[i][j].getX(), k, cubes[i][j].getZ());
					cubes[i][j].drawRedCube();
				}
				else if (cubes[i][j].getColor(k) == BLUE){
					glTranslatef(cubes[i][j].getX(), k, cubes[i][j].getZ());
					cubes[i][j].drawBlueCube();

				}
				else if (cubes[i][j].getColor(k) == GREEN){
					glTranslatef(cubes[i][j].getX(), k, cubes[i][j].getZ());
					cubes[i][j].drawGreenCube();
				}
				else if (cubes[i][j].getColor(k) == YELLOW){
					glTranslatef(cubes[i][j].getX(), k, cubes[i][j].getZ());
					cubes[i][j].drawYellowCube();
				}
				else if (cubes[i][j].getColor(k) == MAGENTA){
					glTranslatef(cubes[i][j].getX(), k, cubes[i][j].getZ());
					cubes[i][j].drawMagentaCube();
				}

				glPopMatrix();
			}
		}
	}
	drawLightsSpheres();
	glFlush();
	glutSwapBuffers();

}
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = 1.0* w / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();



	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 1000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
void checkForSunLight(){

	GLfloat position[] = { sun, 65.0, sun, 1.0f };

	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blackAmbientLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, whiteDiffuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whiteSpecularLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);


	if (sun >= 64 && sunLight == true){
		glDisable(GL_LIGHT0);
		sunLight = false;
	}




}
void turnOffLightNumber(int aLightNumber){

	for (int i = 0; i < 7; i++){
		if (lightNumbers[i] == aLightNumber&&freeLight[i] == 1){
			freeLight[i] = 0;
		}
	}

}
void checkForLights(){
	int k = 0;
	if (lights.empty()){
		lightBall = false;
	}
	while (k < lights.size() && lights.empty() == false){

		if (lights[k].getLightDuration() == 30 && lights[k].getOn() == true){
			int lightNumber = lights[k].getLightNumber();
			turnOffLightNumber(lightNumber);
			glDisable(lightNumber);
			lights.erase(lights.begin() + k);


		}
		else if (lights[k].getLightDuration() < 30 || lights[k].getOn() == false) {

			k++;
		}
	}
}
bool checkHowManyLightsIsOn(){
	int sum = 0;
	bool turnOn = false;
	if (!lights.empty()){
		for (int i = 0; i < lights.size(); i++){
			if (lights[i].getOn()){
				sum++;
			}
		}
	}

	if (sum < 7){
		turnOn = true;
	}

	return turnOn;
}
int getLight(){
	for (int i = 0; i < 7; i++){
		if (freeLight[i] == 0){
			freeLight[i] = 1;
			return i;
		}
	}
}
void init(){

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);

}
void mouse(int button, int state, int xMouse, int yMouse){

	if (sunLight == true || lightBall == true){

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
			if (player.getCubeStock() > 0){
				player.addCube(x, y, z, lx, lz, cubes);
				player.removeCubeStock();
			}
		}
		else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
			player.kickCube(x, y, z, lx, lz, cubes);
		}

	}

}
void processNormalKeys(unsigned char key, int xx, int yy) {


	if (key == ESC)
	{
		glutLeaveGameMode(); //set the resolution how it was
		exit(0); //quit the program
	}
	else if (key == SPACEBAR){

		if (sunLight == true || lightBall == true){

			int x1 = round(x) + 32;
			int z1 = round(z) + 32;
			int color = cubes[x1][z1].getColor(y - 1);
			if (color != MAGENTA&&color != BLUE){
				player.addCubeStock(color - 1);
				cubes[x1][z1].setColor(color - 1, y - 1);

			}
		}
	}
	else if (key == 'w' || key == 'W'){

		if (sunLight == true || lightBall == true){

			if (mo.checkForCube(x, y, z, cubes, lx, lz, key)){
				mo.checkMove(x, z);
				player.checkForPoints(x, y, z, cubes, lx, ly1, lz, key);
				mo.moveUp(x, z, lx, lz);
				sun++;
				for (int i = 0; i < lights.size(); i++){
					if (lights[i].getOn() == true){
						lights[i].addLightDuration();
					}
				}
			}
		}

	}
	else if (key == 's' || key == 'S'){

		if (sunLight == true || lightBall == true){

			if (mo.checkForCube(x, y, z, cubes, lx, lz, key)){
				mo.checkMove(x, z);
				player.checkForPoints(x, y, z, cubes, lx, ly1, lz, key);
				mo.moveDown(x, z, lx, lz);
				sun++;
				if (lights.size()>0){
					for (int i = 0; i < lights.size(); i++){
						if (lights[i].getOn() == true){

							lights[i].addLightDuration();
						}
					}
				}
			}
		}
	}
	else if (key == 'd' || key == 'D'){

		if (sunLight == true || lightBall == true){

			if (mo.checkForCube(x, y, z, cubes, lx, lz, key)){
				mo.checkMove(x, z);
				player.checkForPoints(x, y, z, cubes, lx, ly1, lz, key);
				mo.moveRight(x, z, m.getAngle());
				sun++;
				for (int i = 0; i < lights.size(); i++){
					if (lights[i].getOn() == true){
						lights[i].addLightDuration();
					}
				}
			}
		}
	}
	else if (key == 'a' || key == 'A'){

		if (sunLight == true || lightBall == true){

			if (mo.checkForCube(x, y, z, cubes, lx, lz, key)){
				mo.checkMove(x, z);
				player.checkForPoints(x, y, z, cubes, lx, ly1, lz, key);
				mo.moveLeft(x, z, m.getAngle());
				sun++;
				for (int i = 0; i < lights.size(); i++){
					if (lights[i].getOn() == true){
						lights[i].addLightDuration();
					}
				}
			}
		}

	}
	else if (key == 'q' || key == 'Q'){

		if (sunLight == true || lightBall == true){

			player.destroyCube(x, y, z, lx, lz, cubes);

		}
	}
	else if (key == 'R' || key == 'r'){

		if (sunLight == true || lightBall == true){

			player.dropCube(cubes);

		}

	}
	else if (key == 'E' || key == 'e'){

		if (sunLight == true || lightBall == true){

			player.destroyAllCubes(x, z, lx, lz, cubes);
			lights.push_back(p);

		}

	}
	else if (key == 'v' || key == 'V'){

		if (sunLight == true || lightBall == true){

			glutPassiveMotionFunc(NULL);
			if (view.getVPress() == 0){
				view.firstView(x, y, z, lx, lz);
			}
			else if (view.getVPress() == 1){
				view.secondView(x, y, z, lx, lz);
			}
			else if (view.getVPress() == 2){
				view.thirdView(x, y, z, lx, lz);
			}
			else if (view.getVPress() == 3){
				view.fourthView(x, y, z, lx, lz);
			}if (view.getVPress() == 4){
				view.playerView(x, y, z, lx, lz);
				glutKeyboardFunc(processNormalKeys);
				glutPassiveMotionFunc(mouseCamera);
			}

		}

	}
	else if (key == 'l' || key == 'L'){

		bool on = false;
		if (lights.empty() == false){

			if (checkHowManyLightsIsOn()){

				for (int i = 0; i < lights.size(); i++){
					if (lights[i].getOn() == false && on == false){
						int lightNumber = getLight();
						lights[i].openLight(lightNumbers[lightNumber], x, y, z, lx, lz);
						on = true;
						lightBall = true;

					}
				}
			}
		}
	}
}
void renderScene(void) {

	//Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Reset transformations
	glLoadIdentity();



	// Set the camera
	gluLookAt(x, y, z,
		x + lx, ly1, z + lz,
		0.0f, 1.0f, 0.0f);


	checkForSunLight();
	checkForLights();
	drawScence();
	createPointString();
	createCubeStockString();
	display.displayPoints(pointText->data(), pointText->size());
	display.displayCubeStock(cubeStockText->data(), cubeStockText->length());
	glutSwapBuffers();

}
int main(int argc, char **argv){

	//init Glut and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	//glutInitWindowPosition(100, 100);
	//glutInitWindowSize(500, 500);


	//glutGameModeString("1024Χ768:32@75"); //the settings for fullscreen mode
	//glutEnterGameMode(); //set glut to fullscreen using the settings in the line above
	initNumbers();
	glutCreateWindow("Create your world");
	glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);
	init();

	//register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	//Keyboard functions
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(mouseCamera);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	//enter Glut event processing cyclei
	glutMainLoop();

	return 0;

}
