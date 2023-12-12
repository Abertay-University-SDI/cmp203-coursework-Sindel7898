#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include <vector>
#include"PreceduallyGeneratedShapes.h"

class Lighting {
public:
	float r;
	float g;
	float b;
	float Alpha;	
	int X = 0;
	int Y = 0;
	int Z = 0;

	void Spotlight(GLenum LightName);
	PrecuduallyGeneratedShapes precuduallyGeneratedShapes;
	void ChangingSpotlight(GLenum LightName, int Switcher);

	void RoomLight();

protected:
	Input* input;
};