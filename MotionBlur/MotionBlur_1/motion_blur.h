#pragma once
#include "custom_vars.h"
#include "vars.h"
#include "customizables.h"

void do_movement(float timestep) {
	sphereRotationAng = (sphereRotationAng+timestep*ang_delta);
	if (sphereRotationAng>=360) { sphereRotationAng -= 360; }
}

void idle_func(void) {
	if (motion_blur)
	{
		do_movement(timestep/n);
		drawScene();

		if (i==0)
		{
			glAccum(GL_LOAD, 1.0f/n);
		}
		else
		{
			glAccum(GL_ACCUM, 1.0f/n);
		}
		i++;
		if (i>=n)
		{
			i = 0;
			do_movement(-timestep+timestep/n);
			glAccum(GL_RETURN, 1.0f);
			glutSwapBuffers();
		}
	}
	else if (just_changed)
	{
		just_changed = false;
		i = 0;
		glAccum(GL_RETURN, 1.0);
		//glutPostRedisplay();
		//glutSwapBuffers();

	}
}