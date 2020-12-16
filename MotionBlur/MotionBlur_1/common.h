//common functions
#pragma once
//system includes

//openGL includes
#include <GL/glut.h>

//custom includes 
#include "vars.h"


GLfloat toRad(GLfloat ang) {
	return ang/180.0*PI;
}


void draw_sphere(GLfloat radius, GLfloat slices, GLfloat stacks) {
	if (solid)
	{
		glutSolidSphere(radius, slices, stacks);
	}
	else
	{
		glutWireSphere(radius, slices, stacks);
	}
}

void draw_cube(GLfloat size, GLfloat a = -0, GLfloat b = 0) {
	if (solid)
	{
		glutSolidCube(size);
	}
	else
	{
		glutWireCube(size);
	}
}


/*-------------------------------------------------OpenGL-------------------------------------------------*/

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	if (is_cube)
	{
		draw = &draw_cube;
	}
	else
	{
		draw = &draw_sphere;
	}
}



//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w/(double)h, //The width-to-height ratio
				   1.0,                   //The near z clipping coordinate
				   200.0);                //The far z clipping coordinate
}

//Called when a key is pressed
void handleKeypress_common(unsigned char key, //The key that was pressed
						   int x, int y) {    //The current mouse coordinates
	switch (key)
	{
		case 27: //Escape key
			exit(0); //Exit the program
	}
}

