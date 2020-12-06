#pragma once
//system includes
#include <iostream>

//openGL includes
#include <GL/glut.h>

//custom includes 
#include "vars.h"
#include "common.h"
#include "customizables.h"
#include "custom_vars.h"

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
						   int x, int y)   //The current mouse coordinates
{
	switch (key)
	{
		case 'q'://cube 2 rotation
			std::cout<<"button q pressed"<<std::endl;
			sphereRotationAng = (sphereRotationAng+1.0);
			if (sphereRotationAng>=360) { sphereRotationAng -= 360; }
			glutPostRedisplay();
			break;
		case 'w'://cube 2 rotation
			std::cout<<"button w pressed"<<std::endl;
			sphereRotationAng = (sphereRotationAng-1.0);
			if (sphereRotationAng<=-360) { sphereRotationAng += 360; }
			glutPostRedisplay();
			break;
		case 'e'://to 3 person view
			std::cout<<"button e pressed"<<std::endl;
			view3person = !view3person;
			top_view = false;
			glutPostRedisplay();
			break;
		case 'r'://to top view
			std::cout<<"button r pressed"<<std::endl;
			top_view = !top_view;
			view3person = false;
			glutPostRedisplay();
			break;
		case 't'://to top view
			std::cout<<"button t pressed"<<std::endl;
			random = !random;
			break;
		case 'm':// on/off motion blur
			std::cout<<"button m pressed"<<std::endl;
			motion_blur = !motion_blur;
			just_changed = true;
			//glutPostRedisplay();
			break;
		case 'd':// on/off solid option
			std::cout<<"button s pressed"<<std::endl;
			solid = !solid;
			glutPostRedisplay();
			break;
		case 'f':
			std::cout<<"button s pressed"<<std::endl;
			is_cube = !is_cube;
			if (is_cube)
			{
				draw = &draw_cube;
			}
			else
			{
				draw = &draw_sphere;
			}
			glutPostRedisplay();
			break;
		default: handleKeypress_common(key, x, y);
	}
}


//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	if (view3person)
	{
		gluLookAt(10.0f, 0.0f, 0.0f,
				  0.0f, 0.0f, 0.0f,
				  0.0, 1.0, 0.0);
	}
	else if (top_view)
	{
		gluLookAt(0.0f, 20.0f, 0.0f,
				  0.0f, 0.0f, 0.0f,
				  1.0, 0.0, 0.0);
	}
	else
	{
		gluLookAt(0.0f, 0.0f, 0.0f,
				  10.0f, 0.0f, 0.0f,
				  0.0, 1.0, 0.0);
	}
	if (motion_blur)
	{
		for (int i = 1; i<=n; i++)
		{
			glRotatef(sphereRotationAng-(i*ang_delta)/n, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.0f, 0.0f, 7.0f+(float)i*transform_queficient);
			//std::cout<<sphereRotationAng-(i*ang_delta)/n<<std::endl;
			glColor3f(getCoef()*(n-i)*red/n, getCoef()*(n-i)*green/n, getCoef()*(n-i)*blue/n);
			draw(1.5f, 100, 100);

			glTranslatef(0.0f, 0.0f, -7.0f-(float)i*transform_queficient);
			glRotatef(-(sphereRotationAng-(i*ang_delta)/n), 0.0f, 1.0f, 0.0f);

		}
	}
	else
	{
		glRotatef(sphereRotationAng, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 0.0f, 7.0f);

		glColor3f(red, green, blue);
		draw(1.5f, 100, 100);

		glTranslatef(0.0f, 0.0f, -7.0f);
		glRotatef(-sphereRotationAng, 0.0f, 1.0f, 0.0f);
		glutSwapBuffers(); //Send the 3D scene to the screen
	}
}