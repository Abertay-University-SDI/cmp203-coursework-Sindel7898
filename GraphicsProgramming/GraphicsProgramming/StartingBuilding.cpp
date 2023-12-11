#include"StartingBuilding.h"

//constructor to call the textures 
 StartingBuilding::StartingBuilding(){
	 Floor = SOIL_load_OGL_texture(
		 "gfx/checked.png",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	 Wall = SOIL_load_OGL_texture(
		 "gfx/Wall.png",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	 Stand = SOIL_load_OGL_texture(
		 "gfx/Wood.jpg",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}


 // draws the building and applies relevant texture to specofic parts 
void StartingBuilding::Building() {
	glEnable(GL_LIGHTING);
	material.MaterialSpecifics(1, 40);
	glScalef(80, 20, 40);
	glTranslatef(0, 0.3, 0);
	glBindTexture(GL_TEXTURE_2D, Wall);
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.25f, 0.25f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.75f, 0.25f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.75f, 0.75f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.25f, 0.75f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	//Right Face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.75f, 0.25f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.25f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.75f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.75f, 0.75f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, Floor);
	glBegin(GL_QUADS);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.25f, 0.75f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.75f, 0.75f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.75f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.25f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Wall);
	glBegin(GL_QUADS);
	//Left Face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.25f, 0.25f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 0.25f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.25f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);


	//Top Face
	if (RoofRemover == 1) {

		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 0);
	}
	else
	{
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.25f, 0.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.75f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.75f, 0.25f);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(0.25f, 0.25f);
		glVertex3f(-0.5f, 0.5f, -0.5f);
	}
	

	//Back Face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(1.0f, 0.25f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.75f, 0.25f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.75f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
	


}


void StartingBuilding::DisplayStand(int x, int z) {
	glPushMatrix();
	material.MaterialSpecifics(1, 40);
	glRotatef(90, 0, 0, 1);
	glScalef(4, 3, 4);
	glTranslatef(-0.4, x, z);
	glBindTexture(GL_TEXTURE_2D, Stand);

	// Define vertex positions, texture coordinates, and normals
	GLfloat vertices[] = {
		-0.5f,  0.5f, -0.5f,  // Front Face
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		 0.5f,  0.5f, -0.5f,  // Right Face
		 0.5f,  0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,  // Bottom Face
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,  // Left Face
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f,  0.5f,  // Top Face
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,

		-0.5f,  0.5f,  0.5f,  // Back Face
		 0.5f,  0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f
	};

	GLfloat texCoords[] = {
		0.25f, 0.25f,  // Front Face
		0.75f, 0.25f,
		0.75f, 0.75f,
		0.25f, 0.75f,

		0.75f, 0.25f,  // Right Face
		1.0f,  0.25f,
		1.0f,  0.75f,
		0.75f, 0.75f,

		0.25f, 0.75f,  // Bottom Face
		0.75f, 0.75f,
		0.75f, 1.0f,
		0.25f, 1.0f,

		0.25f, 0.25f,  // Left Face
		0.0f,  0.25f,
		0.0f,  0.5f,
		0.25f, 0.5f,

		0.25f, 0.0f,   // Top Face
		0.75f, 0.0f,
		0.75f, 0.25f,
		0.25f, 0.25f,

		1.0f,  0.25f,  // Back Face
		0.75f, 0.25f,
		0.75f, 0.5f,
		1.0f,  0.5f
	};

	// Set up vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);

	// Draw using vertex arrays
	glDrawArrays(GL_QUADS, 0, 24);

	// Clean up
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glPopMatrix();
}


void StartingBuilding::ReflectionStand(int x, int z) {
	glPushMatrix();
	material.MaterialSpecifics(1, 40);
	glRotatef(90, 0, 0, 1);
	glScalef(4, 3, 4);
	glTranslatef(-0.4, x, z);
	glBindTexture(GL_TEXTURE_2D, Stand);
	glBegin(GL_QUADS);

	glTexCoord2f(0.25f, 0.25f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.75f, 0.25f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.75f, 0.75f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.25f, 0.75f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	//Bottom Face
	glTexCoord2f(0.25f, 0.75f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.75f, 0.75f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.75f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.25f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	//Left Face
	glTexCoord2f(0.25f, 0.25f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 0.25f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.25f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);


	//Top Face
	glTexCoord2f(0.25f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.75f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.75f, 0.25f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.25f, 0.25f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	//Back Face
	glTexCoord2f(1.0f, 0.25f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.75f, 0.25f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.75f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
	glPopMatrix();

}