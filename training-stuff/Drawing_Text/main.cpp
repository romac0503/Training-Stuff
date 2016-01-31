///* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
///**********************************************************************************************************************************/
///**
//   @file      helloWorld.c
//   @author    Mitch Richling <http://www.mitchr.me/>
//   @Copyright Copyright 1997 by Mitch Richling.  All rights reserved.
//   @brief     Simple helloworld program for GLUT.@EOL
//   @Keywords  opengl glut hello world
//   @Std       C99
//***********************************************************************************************************************************/
//
///**********************************************************************************************************************************/
//#ifdef __APPLE__
//#include <GLUT/glut.h>          /* Open GL Util    APPLE */
//#else
//#include <GL/glut.h>            /* Open GL Util    OpenGL*/
//#endif
//
///**********************************************************************************************************************************/
///* You must have a display callback that GLUT calls to draw everything. */
//void displayCall() {
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//  glEnable(GL_DEPTH_TEST);
//
//  glMatrixMode(GL_PROJECTION);
//  glLoadIdentity();
//  glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 500.0);
//
//  glMatrixMode(GL_MODELVIEW);
//  glLoadIdentity();
//  gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//  glScalef(.005,.005,.005);
//  glRotatef(20, 0, 1, 0);
//  glRotatef(30, 0, 0, 1);
//  glRotatef(5, 1, 0, 0);
//  glTranslatef(-300, 0, 0);
//    
//  glColor3f(1,1,1);
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'H');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'e');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'l');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'l');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'o');
//  
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'W');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'o');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'r');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'l');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, 'd');
//  glutStrokeCharacter(GLUT_STROKE_ROMAN, '!');
//        
//  glutSwapBuffers();
//} /* end func displayCall */
//
///**********************************************************************************************************************************/
///* Set up everything, and start the GLUT main loop. */
//int main(int argc, char *argv[]) {
//  glutInit(&argc, argv);
//  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//  glutInitWindowSize(500, 500);
//  glutInitWindowPosition(300, 200);
//  glutCreateWindow("Hello World!");
//  glutDisplayFunc(displayCall);
//  glutMainLoop();
//  return 0;
//} /* end func main */

/* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above notice and this permission notice shall be included in all copies
* or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
/* File for "Drawing Text" lesson of the OpenGL tutorial on
* www.videotutorialsrock.com
*/



#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "text3d.h"

using namespace std;

//Computes a scaling value so that the strings
float computeScale(const char* strs[8]) {
	float maxWidth = 0;
	for (int i = 0; i < 8; i++) {
		float width = t3dDrawWidth(strs[i]);
		if (width > maxWidth) {
			maxWidth = width;
		}
	}

	return 0.6f / maxWidth;
}

float _angle = 0.0f;
float _scale = 0.003;
const char* _text[8] = { "s", "p", "i", "n", "n", "i", "n", "g" };
const int screenWidth = 1400;
const int screenHeight = 1200;
//The four strings that are drawn
//const char* STRS[4] = { "Video", "Tutorials", "Rock", ".com" };
//const char* STRS[4] = { "My", "funny", "cube", "text" };

void cleanup() {
	t3dCleanup();
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		cleanup();
		exit(0);
		break;
	/*default:
		letter = key;*/
	}
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	t3dInit();
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(0.0, (double)w / (double)h, 1.0, 200.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 500.0);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat ambientColor[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor0[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat lightPos0[] = { -0.5f, 0.5f, 1.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	//gluLookAt(0, 0, 200, 0, 0, 0.0, 0.0, 1.0, 0.0);
	//gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-_angle, 0.0f, 1.0f, 0.0f);

	//Draw the strings along the sides of a square
	glScalef(_scale, _scale, _scale);
	for (int i = 0; i < 8; i++) {
		glPushMatrix();
		glRotatef(45 * i, 0, 1, 0);
		glTranslatef(0, 0, 1.5f / _scale);
		glColor3f(1, 1, 1);
		//glutStrokeCharacter(GLUT_STROKE_ROMAN, _text[i]);
		//t3dDraw3D(STRS[i], 0, 0, 0.2f);
		t3dDraw2D(_text[i], 0, 0, 0.2f);

		glPopMatrix();
	}
	
	glutSwapBuffers();
}

void update(int value) {
	_angle += 1.5f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Drawing Text - videotutorialsrock.com");
	initRendering();

	_scale = computeScale(_text);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}









