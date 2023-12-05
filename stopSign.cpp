#include "stopSign.hpp"
#include <GL/glut.h>
#include <cmath>

StopSign::StopSign(float x, float y, float z) : posX(x), posY(y), posZ(z) {}

void StopSign::render() {
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	drawCylinder();
	drawOctagon();
	glPopMatrix();
}

void StopSign::drawCylinder() {
	glColor3f(0.5, 0.5, 0.5); // Grey color for the cylinder
	GLUquadricObj *quadric = gluNewQuadric();

	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Rotate to make the cylinder stand upright

	gluCylinder(quadric, 0.2, 0.2, 1.0, 10, 10); // Cylinder with 1 unit height

	glPopMatrix();
	gluDeleteQuadric(quadric);
}

void StopSign::drawOctagon() {
	glColor3f(1.0, 0.0, 0.0); // Red color for the octagon
	    glPushMatrix();

	    // First translate, then rotate
	    glTranslatef(0.0f, 1.0f, 0.0f); // Move the octagon to the top of the cylinder
	    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rotate the octagon 90 degrees around the Y-axis
	    glTranslatef(0.0f, 0.0f, -0.2f); // Adjust this translation to avoid intersection with the cylinder

	    glBegin(GL_POLYGON);
	    for(int i = 0; i < 8; ++i) {
	        float angle = 2.0 * M_PI * i / 8;
	        glVertex3f(0.5 * cos(angle), 0.5 * sin(angle), 0.0); // Define the octagon vertices
	    }
	    glEnd();

	    glPopMatrix();
}
