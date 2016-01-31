// Transformations_and_Timers.cpp : Defines the entry point for the console application.
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

// Include GLEW
#include <GLEW\glew.h>

// Include GLFW
#include <GLFW\glfw3.h>

// Include GLUT
#include <GL\glut.h>
#endif

using namespace std;

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates
	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	}
}

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}

float _angle = 30.0f;
float _triangleAngle = 60.0f;
float _trapezoidAngle = 120.0f;
float _pentagonAngle = 10.0f;
float _cameraAngle = 0.0f;

int timer = 0;
int counter = 0;

void ColorChanger(int n){
	if (n == 0)			glColor3f(1.0f, 0.0f, 0.0f);
	else if (n == 1)	glColor3f(0.0f, 1.0f, 0.0f);
	else if (n == 2)	glColor3f(0.0f, 0.0f, 1.0f);
}

//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.1f, -0.1f, 1.0f); //Rotate the camera
	glTranslatef(0.0f, 0.0f, -5.0f); //Move forward 5 units
	glScalef(0.5f, 0.5f, 0.5f);

	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0f, -1.0f, 0.0f); //Move to the center of the trapezoid
	glRotatef(_trapezoidAngle, 0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3f(0.5f, 0.0f, 1.0f);

	//Trapezoid
	glColor3f(0.5f, 0.0f, 0.8f);
	glVertex3f(-0.7f, -0.5f, 0.0f);
	glColor3f(0.0f, 0.9f, 0.0f);
	glVertex3f(0.7f, -0.5f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.4f, 00.5f, 0.0f);
	glColor3f(0.0f, 0.65f, 0.65f);
	glVertex3f(-0.4f, 0.5f, 0.0f);

	glEnd(); //End quadrilateral coordinates

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5f, 0.0f, 0.0f);

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(1.0f, 1.0f, 0.0f); //Move to the center of the pentagon
	glRotatef(_pentagonAngle, 0.0f, 1.0f, 0.0f); //Rotate about the y-axis
	glScalef(0.7f, 0.7f, 0.7f); //Scale by 0.7 in the x, y, and z directions

	glBegin(GL_TRIANGLES); //Begin triangle coordinates
	ColorChanger(counter);
	
	//Pentagon
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glEnd();

	glPopMatrix(); //Undo the move to the center of the pentagon
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1.0f, 1.0f, 0.0f); //Move to the center of the triangle
	glRotatef(_triangleAngle, 1.0f, 2.0f, 3.0f); //Rotate about the the vector (1, 2, 3)

	glBegin(GL_TRIANGLES);

	//Triangle
	glColor3f(1.0f, 0.7f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glEnd(); //End triangle coordinates

	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers(); //Send the 3D scene to the screen

}

void update(int value) {
	
	timer += 1;

	if (timer == 40){
		counter++;
		timer = 0;
	}

	if (counter > 2){
		counter = 0;
	}

	_angle += 2.0f;
	_cameraAngle += 2.0f;
	_triangleAngle += 5.0f;
	_trapezoidAngle += 0.5f;
	_pentagonAngle += 30.0f;

	

	if (_cameraAngle > 360){
		_cameraAngle -= 360;
	}

	if (_triangleAngle > 360) {
		_triangleAngle -= 360;
	}

	if (_trapezoidAngle > 360){
		_trapezoidAngle -= 360;
	}

	if (_pentagonAngle > 360){
		_pentagonAngle -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the scene has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char* argv[])
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); //Set the window size

	//Create the window
	glutCreateWindow("Basic Shapes - videotutorialsrock.com");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.

	return 0;
}

