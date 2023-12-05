#include <iostream>
#include <GL/glut.h>
#include "cube.cpp"

float cameraAngleX = 40.0f;
float cameraAngleY = 00.0f;
float cameraDistance = 35.0f;

bool cubePositions[20][20] = {false};
//cube cubesBuilt[20][20];
cube blackSquares[20][20];


cube grayCube(0, 0);  // Adjust the grid position of the gray cube

cube testCube(2, 2);  // Adjust the grid position of the gray cube


void drawCube(float x, float y) {
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0); // Green color for cubes
	glTranslatef(x, 0.2, y);
	glutSolidCube(0.4);
	glPopMatrix();
}


void drawCubes() {

	int gridX = static_cast<int>(grayCube.getX() + 0.5);
	int gridY = static_cast<int>(grayCube.getY() + 0.5);

	// Check if the position is within the grid boundaries
	if (gridX >= 0 && gridX < 20 && gridY >= 0 && gridY < 20) {
		// Mark the position as occupied
		cubePositions[gridX][gridY] = true;
        blackSquares[gridX][gridY] = cube(gridX, gridY);

		//cube temp(gridX+1, gridY+1);  // Adjust the grid position of the gray cube
		//temp.draw();
		//glutSwapBuffers();
		//drawCubes();
	}
}



void drawGrid() {
	glLineWidth(2);

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			glPushMatrix();

			glTranslatef(i, 0, j);

			if (j == 10 || i == 10) {
				glColor3f(0.7, 0.7, 0.7); // Gray color
			} else if (cubePositions[i][j]) {
				//cube cubesBuilt[i][j] = drawCube(i, j);
				//'cubesBuilt[i][j].draw();  // Draw the cube at the specified position

				//glScalef(2.5, 2.5, 2.5);
				//glColor3f(1.0, 1.0, 1.0); // new color for occupied positions


			} else {
				glColor3f(0.0, 1.0, 0.0); // Default green color
			}

			glBegin(GL_QUADS);
			glVertex3f(0, 0, 0);
			glVertex3f(1, 0, 0);
			glVertex3f(1, 0, 1);
			glVertex3f(0, 0, 1);
			glEnd();

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
	testCube.draw();

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			if(cubePositions[i][j] == true)
			{
				                blackSquares[i][j].draw();

			}
		}
	}


	// Draw the gray cube
	//grayCube.draw();
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

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		grayCube.move(0.0f, -1.0f);
		break;
	case 's':
		grayCube.move(0.0f, 1.0f);
		break;
	case 'a':
		grayCube.move(-1.0f, 0.0f);
		break;
	case 'd':
		grayCube.move(1.0f, 0.0f);
		break;
	case 'b':
		drawCubes();
		// Calculate grid position
		//		int gridX = static_cast<int>(grayCube.getX() + 0.5);
		//		int gridY = static_cast<int>(grayCube.getY() + 0.5);
		//
		//		// Check if the position is within the grid boundaries
		//		//if (gridX >= 0 && gridX < 20 && gridY >= 0 && gridY < 20) {
		//			// Mark the position as occupied
		//			cubePositions[gridX][gridY] = true;
		//			cube temp(gridX+1, gridY+1);  // Adjust the grid position of the gray cube
		//			temp.draw();
		//			glutSwapBuffers();
		//			drawCubes();
		//glutSolidCube(0.4);
		//            for (int i = 0; i < 20; ++i) {
		//                for (int j = 0; j < 20; ++j) {
		//
		//                    //cubesBuilt[i][j] = cube(i, j);
		//                }
		//            }
		//cubesBuilt[gridX][gridY] = temp;
		//cubesBuilt[gridX][gridY].draw();
		//}

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
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}
