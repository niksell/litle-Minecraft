
#include "Light.h"
/*#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
*/
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

	GLfloat whiteSpecularLight[] = { 1.0, 1.0, 1.0 };
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



