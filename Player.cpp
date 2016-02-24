
#include "Player.h"

#define BLUE		1
#define YELLOW		2
#define RED		3
#define GREEN		4
#define MAGENTA		5


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
		if(cubes[i1][i2].getColor(y)!=0){
			cubes[i1][i2].setColor(0, y);
		}

	}
	else if (round(lx) == 1 && round(lz) == 0){

		int i1 = round(x + 1) + 32;
		int i2 = round(z) + 32;
		if(cubes[i1][i2].getColor(y)!=0){
			cubes[i1][i2].setColor(0, y);
		}

	}
	else if (round(lx) == 0 && round(lz) == 1){

		int i1 = round(x) + 32;
		int i2 = round(z + 1) + 32;
		if(cubes[i1][i2].getColor(y)!=0){
			cubes[i1][i2].setColor(0, y);
		}
	}
	else if (round(lx) == -1 && round(lz) == 0){

		int i1 = round(x - 1) + 32;
		int i2 = round(z) + 32;
		if(cubes[i1][i2].getColor(y)!=0){
			cubes[i1][i2].setColor(0, y);
		}
	}
}
bool Player::destroyAllCubes(float x, float z, float lx, float lz, Cube cubes[64][64]){

	if (round(lx) == 0 && round(lz) == -1){

		int i1 = round(x) + 32;
		int i2 = round(z) + 32 - 1;
		if(cubes[i1][i2].getColor(0)!=0){
			for (int k = 0; k <64; k++){
				if (cubes[i1][i2].getColor(k) != MAGENTA){
					cubes[i1][i2].setColor(0, k);
				}

			}
			points -= 5;
			return true;
		}else{
		
			return false;

		}
	}
	else if (round(lx) == 1 && round(lz) == 0){
		int i1 = round(x) + 32 + 1;
		int i2 = round(z) + 32;
		if(cubes[i1][i2].getColor(0)!=0){
			for (int k = 0; k <64; k++){
				if (cubes[i1][i2].getColor(k) != MAGENTA){
					cubes[i1][i2].setColor(0, k);
				}

			}
			points -= 5;
			return true;
		}else{
		
			return false;

		}

	}
	else if (round(lx) == 0 && round(lz) == 1){
		int i1 = round(x) + 32;
		int i2 = round(z) + 32 + 1;
		if(cubes[i1][i2].getColor(0)!=0){
			for (int k = 0; k <64; k++){
				if (cubes[i1][i2].getColor(k) != MAGENTA){
					cubes[i1][i2].setColor(0, k);
				}

			}
			points -= 5;
			return true;
		}else{
		
			return false;

		}

	}
	else if (round(lx) == -1 && round(lz) == 0){
		int i1 = round(x) + 32 - 1;
		int i2 = round(z) + 32;
		if(cubes[i1][i2].getColor(0)!=0){
			for (int k = 0; k <64; k++){
				if (cubes[i1][i2].getColor(k) != MAGENTA){
					cubes[i1][i2].setColor(0, k);
				}

			}
			points -= 5;
			return true;
		}else{
		
			return false;

		}
	}

	

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




