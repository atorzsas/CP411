#include <iostream>
#include <GL/glut.h>

float cameraAngleX = 40.0f;
float cameraAngleY = 0.0f;
float cameraDistance = 35.0f;

void testCube() {
	glColor3f(1, 1, 1);//white
	glutSolidCube(0.4);
}

void drawGrid() {
	glLineWidth(2); // Increase the line width for better visibility

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			glPushMatrix();

			glTranslatef(i, 0, j);  // Translate to the grid position

			// Default green for all squares
			glColor3f(0.0, 1.0, 0.0);  // Green color

			//            if (i == 2 && j == 0) {
			//                glColor3f(1.0, 0.0, 0.0); // Red color
			//            }

			// Add a condition for the gray line down the middle and across
			if (j == 10) {
				glColor3f(0.7, 0.7, 0.7); // Gray color
			}
			if (i == 10) {
				glColor3f(0.7, 0.7, 0.7); // Gray color
			}

			glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(1, 0, 0);
			glVertex3f(1, 0, 1);
			glVertex3f(0, 0, 1);
			glEnd();

			// Draw black outlines for each square
			glColor3f(0.0, 0.0, 0.0); // Black color for outlines
			glBegin(GL_LINE_LOOP);
			glVertex3f(0, 0, 0);
			glVertex3f(1, 0, 0);
			glVertex3f(1, 0, 1);
			glVertex3f(0, 0, 1);
			glEnd();

			glPopMatrix();
		}
	}
}

void updateCamera() {
	glTranslatef(0, 0, -cameraDistance);
	glRotatef(cameraAngleX, 1, 0, 0);
	glRotatef(cameraAngleY, 0, 1, 0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	updateCamera();

	drawGrid();
	// testCube();

	glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		cameraAngleX += 5.0f;
		break;
	case GLUT_KEY_DOWN:
		cameraAngleX -= 5.0f;
		break;
	case GLUT_KEY_LEFT:
		cameraAngleY -= 5.0f;
		break;
	case GLUT_KEY_RIGHT:
		cameraAngleY += 5.0f;
		break;
	}

	glutPostRedisplay();
}

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35, 1.0f, 0.01f, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1, 0.1, 0.1, 1);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 900);
	glutCreateWindow("City Builder");
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	init();
	glutMainLoop();
	return 0;
}
