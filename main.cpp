
#include "Utils.h"
#include "Display.h"
#include "View.h"
#include "Cube.h"
#include "MouseCamera.h"
#include "Move.h"
#include "Player.h"
#include "Light.h"


#define BLUE		1
#define YELLOW		2
#define RED		3
#define GREEN		4
#define MAGENTA		5
#define ESC		27
#define SPACEBAR	32
#define lightSphereOff	30
#define sunOff		64

GLfloat whiteSpecularLight[] = { 1.0, 1.0, 1.0 }; //set the light specular to white
GLfloat blackAmbientLight[] = { 0.0, 0.0, 0.0 }; //set the light ambient to black
GLfloat whiteDiffuseLight[] = { 1.0, 1.0, 1.0 }; //set the diffuse light to white
GLfloat blankMaterial[] = { 0.0, 0.0, 0.0 }; //set the diffuse light to white
GLfloat mShininess[] = { 128 }; //set the shininess of the material


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


	if (sun >= sunOff && sunLight == true){
		glDisable(GL_LIGHT0);
		sunLight = false;
	}




}
void turnOffLightNumber(int aLightNumber){

	for (int i = 0; i < 7; i++){
		if (lightNumbers[i] == aLightNumber){
			freeLight[i] = 0;
		}
	}

}
void checkForLights(){
	
	if(lights.empty() == false){
		int k = 0;
		while (k < lights.size()&&lights.empty() == false){
			
			
			if (lights[k].getLightDuration() >= lightSphereOff){
			
				int lightNumber = lights[k].getLightNumber();
				turnOffLightNumber(lightNumber);
				glDisable(lightNumber);
				lights.erase(lights.begin() + k);
				
			}
			
			else{ 
				k++;
				
			}
			
			
		}
	}else if (lights.empty()==true){
		lightBall = false;
	}
}
bool checkHowManyLightsIsOn(){
	int sum = 0;
	bool turnOn = false;
	if (!lights.empty()){
		for (int i = 0; i < lights.size(); i++){
			if (lights[i].getOn()==true){
				sum++;
			}
		}
		if(sum==0){
			lightBall = false;
		}else{

			lightBall = true;
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
				if (!lights.empty()){
					for (int i = 0; i < lights.size(); i++){
						if (lights[i].getOn() == true){
							lights[i].addLightDuration();
						}
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
				if (!lights.empty()){
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
				if (!lights.empty()){
					for (int i = 0; i < lights.size(); i++){
						if (lights[i].getOn() == true){
							lights[i].addLightDuration();
						}
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
				if (!lights.empty()){
					for (int i = 0; i < lights.size(); i++){
						if (lights[i].getOn() == true){
							lights[i].addLightDuration();
						}
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

			if(player.destroyAllCubes(x, z, lx, lz, cubes)){

				lights.push_back(p);
			}

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


	checkHowManyLightsIsOn();
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
	

	glutGameModeString("1080Χ1920:32"); //the settings for fullscreen mode
	glutEnterGameMode(); //set glut to fullscreen using the settings in the line above

	initNumbers();
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
