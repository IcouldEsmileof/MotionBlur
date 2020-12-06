//common variables
#pragma once
#include <GL/glut.h>

GLfloat angX = 0;
GLfloat angY = 0;
GLfloat angZ = 0;
GLfloat angX_1 = 0;
GLfloat angY_1 = 0;
GLfloat angZ_1 = 0;
GLfloat sphereRotationAng_Y = 0.0f;
GLfloat sphereRotationAng_Z = 0.0f;
GLfloat eyeY = 0;
GLfloat eyePosX = 0;
GLfloat eyePosZ = 0;
int mousePosX = -1;
int mousePosY = -1;
GLfloat centerPosX = 0;
GLfloat centerPosY = 0;
GLfloat centerPosZ = -1;
GLfloat dirAng = 0;
GLfloat speed = 1;
const double PI = 3.141592653589793238463;
GLfloat sphereRotationAng = 90.0f;
bool view3person = false;
bool top_view = false;
bool motion_blur = false;
int i = 0;
bool just_changed = false;
bool solid = false;
bool is_idle_synced = false;