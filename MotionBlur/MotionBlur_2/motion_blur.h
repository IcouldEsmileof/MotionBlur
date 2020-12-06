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
		do_movement(1.0f);
		drawScene();

		glutSwapBuffers();
	}
}