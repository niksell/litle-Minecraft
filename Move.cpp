
#include "Move.h"


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
	else if (round(x)+32 > 62){

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
	
	//check x and z in order to don't get out of bounds

	if(x1>62){
	
		x1--;

	}else if(x1<1){

		x1++;

	}

	if(z1>62){
	
		z1--;

	}else if(z1<1){

		z1++;

	}

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



