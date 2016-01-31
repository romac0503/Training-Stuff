// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

// Include GLEW
#include <GLEW/glew.h>

// Include GLFW
#include <GLFW\glfw3.h>

// Include GLUT
#include <GL\glut.h>
#define MAXLEVELS 10


// Include GLM
#include <glm/glm.hpp>
using namespace glm;
using namespace std;

GLFWwindow* window;

vec2 start;
vec2 end;
float lineLength;

void CalcPos(float startPosX, float startPosY, float length, int n)
{

	if (n > 0)
	{
		//drawing root branch
		glBegin(GL_LINES);
		glVertex2f(startPosX, startPosY);
		glVertex2f(startPosX, startPosY + length);
		glEnd();


		// drawing left branch
		glBegin(GL_LINES); // drawing only done here
		glVertex2f(startPosX, startPosY + length);
		glVertex2f(startPosX - length / 2, startPosY + length);
		glVertex2f(startPosX - length / 2, startPosY + length);
		glVertex2f(startPosX - length / 2, startPosY + 2 * length);
		glEnd();

		// drawing right branch
		glBegin(GL_LINES);
		glVertex2f(startPosX, startPosY + length);
		glVertex2f(startPosX + length / 2, startPosY + length);
		glVertex2f(startPosX + length / 2, startPosY + length);
		glVertex2f(startPosX + length / 2, startPosY + 2 * length);
		glEnd();

		CalcPos(startPosX - length / 2, startPosY + 2 * length, length / (float)2, n - 1);
		CalcPos(startPosX + length / 2, startPosY + 2 * length, length / (float)2, n - 1);
	}
}

void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	lineLength = (1 / (float)MAXLEVELS);
}

void idle()
{
	glutPostRedisplay();
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	CalcPos(0.5, 0, lineLength, MAXLEVELS);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glLoadIdentity();
	glutInitWindowSize(1800, 1400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Recursion");
	glutDisplayFunc(Draw);
	glutIdleFunc(idle);
	Initialize();
	glutMainLoop();
	return 0;
}




///* recursive_circle.c
//* This is a simple, introductory OpenGL program.
//* It draws a circle on a white background by recursively
//* subdividing the sides of a square and renormalizing
//* the distance from the origin.
//*/
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <GLUT/glut.h>
//
//int n = 2;	// the number of levels of recursion
//void init(void)
//{
//	/* select clearing color as white */
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	/* initialize viewing values */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//}
//
//// the recursive function
//void drawside(float x0, float y0, float x1, float y1, int n)
//{
//	float xm, ym, norm;
//	if (n <= 0) { // the stopping condition
//		glBegin(GL_LINES); // drawing only done here
//		glVertex3f(x0, y0, 0.0);
//		glVertex3f(x1, y1, 0.0);
//		glEnd();
//		glBegin(GL_LINES);
//		glVertex3f(x0, y0, 0.0);
//		glVertex3f(x0, y0 + 1, 0.0);
//		glEnd();
//	}
//	else{ // the recursion
//		n--; // decriment counter
//		xm = 0.5*(x0 + x1); // calculate midpoints
//		ym = 0.5*(y0 + y1);
//		norm = sqrt(xm*xm + ym*ym);
//		xm = xm / norm; // normalize line
//		ym = ym / norm;
//		drawside(x0, y0, xm, ym, n);
//		drawside(xm, ym, x1, y1, n);
//	}
//}
//
//void display(void)	// the new display function
//{
//	float x0, y0;
//	/* clear all pixels */
//	glClear(GL_COLOR_BUFFER_BIT);
//	/*
//	* set initial sides of square with unit "radius"
//	* centered at (0.0, 0.0, 0.0).
//	*/
//	glColor3f(1.0, 0.0, 0.0);
//	x0 = 1.0 / sqrt(2.0);
//	y0 = x0;
//	drawside(x0, y0, -x0, y0, n);
//	drawside(-x0, y0, -x0, -y0, n);
//	drawside(-x0, -y0, x0, -y0, n);
//	drawside(x0, -y0, x0, y0, n);
//	glFlush();
//}
//
//int main(int argc, char** argv)
///*
//* Declare initial window size, position, and
//* display mode (single buffer and RGBA).
//* Open window with "circle" * in its title bar.
//* Call initialization routines.
//* Register callback function to display graphics.
//* Enter main loop and process events.
//*/
//{
//	if (argc == 2) sscanf(argv[1], "%i", &n);
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("circle");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0; /* ANSI C requires main to return int. */
//}



//#define ANGLE 0.2
//#define SCALE 0.9
//#define RAND 0.01
//
////---------------------------------------
//// Calculate random value between [-R..R]
////---------------------------------------
//float myrand(float R)
//{
//	return (2 * R * rand()) / RAND_MAX - R;
//}
//
////---------------------------------------
//// Recursive function to create trees
////---------------------------------------
//void tree(float x1, float y1, float length1, float angle1, int depth)
//{
//	if (depth > 0)
//	{
//		// Draw line segment
//		float x2 = x1 + length1 * cos(angle1);
//		float y2 = y1 + length1 * sin(angle1);
//		glVertex2f(x1, y1);
//		glVertex2f(x2, y2);
//
//		// Make two recursive calls
//		float length2 = length1 * (SCALE + myrand(RAND));
//		float angle2 = angle1 + ANGLE + myrand(RAND);
//		tree(x2, y2, length2, angle2, depth - 1);
//		length2 = length1 * (SCALE + myrand(RAND));
//		angle2 = angle1 - ANGLE + myrand(RAND);
//		tree(x2, y2, length2, angle2, depth - 1);
//	}
//}
//
////---------------------------------------
//// Init function for OpenGL
////---------------------------------------
//void init()
//{
//	// Initialize OpenGL
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	float radius = 100;
//	glOrtho(-radius, radius, -radius, radius, -radius, radius);
//}
//
////---------------------------------------
//// Display callback for OpenGL
////---------------------------------------
//void display()
//{
//	// Draw tree
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_LINES);
//	tree(0, -80, 20, 1.5, 10);
//	glEnd();
//	glFlush();
//}
//
////---------------------------------------
//// Idle callback for OpenGL
////---------------------------------------
//void idle()
//{
//	if (system("sleep 2"));
//	glutPostRedisplay();
//}
//
////---------------------------------------
//// Main program
////---------------------------------------
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	glutCreateWindow("Tree");
//	glutDisplayFunc(display);
//	glutIdleFunc(idle);
//	init();
//	glutMainLoop();
//	return 0;
//}