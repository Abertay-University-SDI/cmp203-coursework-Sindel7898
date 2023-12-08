#pragma once
// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include <vector>
#include "Camera1.h"
class Skybox
{
public:
	Skybox();
	void drawSkybox();
	GLuint SKYBOX;
private:
	Camera camera;
};