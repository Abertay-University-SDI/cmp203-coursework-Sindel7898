#include "Material.h"

void Material::MaterialSpecifics(float specular,int shininess) {
	GLfloat mat_specular[] = { specular, specular, specular, specular };
	GLfloat Shine = shininess;

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMateriali(GL_FRONT, GL_SHININESS, Shine);

}