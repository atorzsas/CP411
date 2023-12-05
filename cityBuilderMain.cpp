#include <iostream>
#include <GL/glut.h>
#include "cube.cpp"

float cameraAngleX = 40.0f;
float cameraAngleY = 00.0f;
float cameraDistance = 35.0f;

void updateSunPosition();

// Sun position and color
GLfloat sunPosition[] = { 0.0f, 10.0f, 0.0f, 0.0f };  // Directional light
GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };

bool sunEnabled = true;  // Initially, the sun is enabled

bool cubePositions[20][20] = {false};
//cube cubesBuilt[20][20];
//cube blackSquares[20][20];


cube grayCube(0, 0);  // Adjust the grid position of the gray cube

cube testCube(2, 2);  // Adjust the grid position of the gray cubeb


void drawCube(float x, float y) {
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0); // Green color for cubes
    glTranslatef(x, 0.2, y);
    // Bottom face
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-0.2, 0.0, -0.2);
    glVertex3f(0.2, 0.0, -0.2);
    glVertex3f(0.2, 0.0, 0.2);
    glVertex3f(-0.2, 0.0, 0.2);
    glEnd();
    // ... Add other faces with appropriate normals ...
    glPopMatrix();
}



void drawCubes() {

//	int gridX = static_cast<int>(grayCube.getX() + 0.5);
//	int gridY = static_cast<int>(grayCube.getY() + 0.5);
//
//	// Check if the position is within the grid boundaries
//	if (gridX >= 0 && gridX < 20 && gridY >= 0 && gridY < 20) {
//		// Mark the position as occupied
//		cubePositions[gridX][gridY] = true;
//        //blackSquares[gridX][gridY] = cube(gridX, gridY);
//
//		//cube temp(gridX+1, gridY+1);  // Adjust the grid position of the gray cube
//		//temp.draw();
//		//glutSwapBuffers();
//		//drawCubes();
//	}
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
    updateSunPosition();  // Add this line before drawing anything

	drawGrid();
	testCube.draw();

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			if(cubePositions[i][j] == true)
			{
				                //blackSquares[i][j].draw();

			}
		}
	}


	// Draw the gray cube
	grayCube.draw();
	glutSwapBuffers();
}


void updateSunPosition() {
    if (sunEnabled) {
        glEnable(GL_LIGHT0); // Enable the sun
        glLightfv(GL_LIGHT0, GL_POSITION, sunPosition); // Update sun position
    } else {
        glDisable(GL_LIGHT0); // Disable the sun
    }
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
    case 't':
        sunEnabled = !sunEnabled;
        break;
	case 'b':
		//drawCubes();
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
    case 'j':
        sunPosition[0] -= 1.0f;
        break;
    case 'l':
        sunPosition[0] += 1.0f;
        break;
    case 'i':
        sunPosition[1] += 1.0f;
        break;
    case 'k':
        sunPosition[1] -= 1.0f;
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

    // Lighting setup
    glEnable(GL_LIGHTING);     // Enable lighting
    glEnable(GL_LIGHT0);       // Enable light #0
    glEnable(GL_COLOR_MATERIAL); // Enable color tracking
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // Set material properties to follow glColor values

    // Set light properties
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
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
