// Textured_Cube.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>

// Include GLEW
#include <GLEW/glew.h>

// Include GLFW
#include <GLFW\glfw3.h>

// Include GLUT
#include <GL\glut.h>
#endif


#define PI 3.14159
#include "ImageLoader.h"

using namespace std;

//const float BOX_SIZE = 7.0f; //The length of each side of the cube
const float BOX_SIZE1 = 3.0f;
const float BOX_SIZE2 = 5.0f;
float _angle1 = 0;            //The rotation of the box
float _angle2 = 0;

float _lightAngle = 0;
float _steps = ((float) 1.0f / (float)100);

GLuint _textureId;           //The OpenGL id of the texture

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
	}
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGB,
		image->width, image->height,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		image->pixels);
	return textureId;
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	Image* image = loadBMP("vtr.bmp");
	_textureId = loadTexture(image);
	delete image;
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void DrawSphere(double r, int lats, int longs)
{
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = PI * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = PI * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		glBegin(GL_QUAD_STRIP);

		for (j = 0; j <= longs; j++) {
			double lng = 2 * PI * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glColor3f(1.0f, 1.0f, 0.0f);
			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(x * zr0, y * zr0, z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(x * zr1, y * zr1, z1);
		}
	}
	glEnd();
}

void DrawCube(float size)
{
	glBegin(GL_QUADS);

	//Top face
	glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glVertex3f(-size / 2, size / 2, size / 2);
	glVertex3f(size / 2, size / 2, size / 2);
	glVertex3f(size / 2, size / 2, -size / 2);

	//Bottom face
	glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glVertex3f(size / 2, -size / 2, size / 2);
	glVertex3f(-size / 2, -size / 2, size / 2);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-size / 2, size / 2, size / 2);
	glVertex3f(-size / 2, size / 2, -size / 2);

	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glVertex3f(size / 2, size / 2, -size / 2);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(size / 2, size / 2, size / 2);
	glVertex3f(size / 2, -size / 2, size / 2);

	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-size / 2, size / 2, size / 2);

	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(size / 2, -size / 2, -size / 2);

	glEnd();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	glTranslatef(0.0f, 0.0f, -20.0f);
	
	GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	
	GLfloat lightColor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat lightPos[] = { (-6 * BOX_SIZE1) * _lightAngle, BOX_SIZE1, (4 * BOX_SIZE1) * _lightAngle, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// first cube
	glPushMatrix();
	glTranslatef(-10.0f, 0.0f, 0.0f);
	glRotatef(-_angle1, 0.0f, 1.0f, 1.0f);
	DrawCube(BOX_SIZE1);
	glPopMatrix();

	// second cube
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(_angle2, 1.0f, 1.0f, 0.0f);
	DrawCube(BOX_SIZE1);
	glPopMatrix();

	// first sphere
	glPushMatrix();
	glTranslatef(10.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 0.2f, 0.5f);
	glutSolidSphere(2.0f, 10, 10);
	//DrawSphere(1.0, 10, 10);
	glPopMatrix();

	// second sphere
	glPushMatrix();
	glTranslatef(15.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 0.2f, 0.5f);
	DrawSphere(1.0, 10, 10);
	glPopMatrix();


	glDisable(GL_TEXTURE_2D);

	glutSwapBuffers();
}

void updateSteps(float &step)
{
	if (abs(_lightAngle) <= 1.0f)
	{
		_lightAngle += step;

		if (abs(_lightAngle) > 1.0)
		{
			step *= -1.0f;
			_lightAngle += step;
		}
	}
}

void updateAngle(float steps, float &angle)
{
	angle += steps;
	if (angle > 360) {
		angle -= 360;
	}
}

//Called every 25 milliseconds
void update(int value) {
	updateAngle(5, _angle1);
	updateAngle(1, _angle2);

	updateSteps(_steps);

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1940, 1080);

	glutCreateWindow("Putting It All Together - videotutorialsrock.com");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}

