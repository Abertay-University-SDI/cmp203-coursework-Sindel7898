#include "Lighting.h"

// Function to set up a basic spotlight with default parameters
void Lighting::Spotlight(GLenum LightName)
{
	// Push the current matrix onto the stack to avoid affecting other transformations
	glPushMatrix();

	// Define the properties of the light
	GLfloat Light_Diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat Light_Position[] = { 0.0f, 0.1f, 0.0f, 1.0f };
	GLfloat Light_Ambient[] = { 0.9f, 0.9f, 0.9f, 1.0f };
	GLfloat Spot_Direction[] = { 0.0f, -1.0f, 0.0f };

	// Set light properties using OpenGL functions
	glLightfv(LightName, GL_DIFFUSE, Light_Diffuse);
	glLightfv(LightName, GL_POSITION, Light_Position);
	glLightfv(LightName, GL_AMBIENT, Light_Ambient);
	glLightfv(LightName, GL_SPOT_DIRECTION, Spot_Direction);
	glLightf(LightName, GL_SPOT_CUTOFF, 75.0f);
	glLightf(LightName, GL_SPOT_EXPONENT, 10.0f);

	// Enable the specified light
	glEnable(LightName);

	// Restore the previous matrix from the stack
	glPopMatrix();
}

// Function to control the color of a spotlight based on a switcher value
void Lighting::ChangingSpotlight(GLenum LightName,int Switcher)
{
	// Switch to control the color, storing RGB and alpha values
	switch (Switcher)
	{
	default:
		r = 1.0f;
		g = 1.0f;
		b = 1.0f;
		Alpha = 1.0f;
		break;

	case 1:
		r = 1.0f;
		g = 0.0f;
		b = 0.0f;
		Alpha = 1.0f;
		break;

	case 2:
		r = 1.0f;
		g = 0.0f;
		b = 1.0f;
		Alpha = 1.0f;
		break;

	case 3:
		r = 0.0f;
		g = 0.0f;
		b = 1.0f;
		Alpha = 1.0f;
		break;
	}

	// Push the current matrix onto the stack
	glPushMatrix();

	// Define the properties of the changing spotlight
	GLfloat Light_Diffuse[] = { r, g, b, Alpha };
	GLfloat Light_Position[] = { 0.0f, 0.1f, 0.0f, 1.0f };
	GLfloat Light_Ambient[] = { r, g, b, Alpha };
	GLfloat Spot_Direction[] = { 0.0f, -1.0f, 0.0f };

	// Set light properties using OpenGL functions
	glLightfv(LightName, GL_DIFFUSE, Light_Diffuse);
	glLightfv(LightName, GL_POSITION, Light_Position);
	glLightfv(LightName, GL_AMBIENT, Light_Ambient);
	glLightfv(LightName, GL_SPOT_DIRECTION, Spot_Direction);
	glLightf(LightName, GL_SPOT_CUTOFF, 75.0f);
	glLightf(LightName, GL_SPOT_EXPONENT, 10.0f);

	// Enable the specified light
	glEnable(LightName);
	// Restore the previous matrix from the stack
	glPopMatrix();
}


void Lighting::RoomLight()
{
	// Push the current matrix onto the stack to avoid affecting other transformations
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, NULL);
	glTranslatef(X, Y, 0);
	precuduallyGeneratedShapes.Sphere(60);
	glPopMatrix();

	glPushMatrix();
	// Define the properties of the light
	GLfloat Light_Diffuse[] = { 1.0f, 0.0f, 1.0f, 1.0f};
	GLfloat Light_Position[] = { X, Y, Z, 1.0f };
	GLfloat Light_Ambient[] = { 1.0f, 0.0f, 1.0f, 1.0f };

	// Set light properties using OpenGL functions
	glLightfv(GL_LIGHT7, GL_DIFFUSE, Light_Diffuse);
	glLightfv(GL_LIGHT7, GL_POSITION, Light_Position);
	glLightfv(GL_LIGHT7, GL_POSITION, Light_Ambient);

	glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, 0.5);
	glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.0);

	// Enable the specified light
	glEnable(GL_LIGHT7);

	// Restore the previous matrix from the stack
	glPopMatrix();
}
