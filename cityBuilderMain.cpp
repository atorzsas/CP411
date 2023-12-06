#include <iostream>
#include <GL/glut.h>
#include "cube.cpp"
#include "menu.hpp"
#include "rectangle.cpp" // Include the Rectangle class
#include "rectangle.hpp" // Include the Rectangle class
#include "stopSign.hpp"
#include "car.hpp"

#include <list>



float cameraAngleX = 40.0f;
float cameraAngleY = 00.0f;
float cameraDistance = 35.0f;

void updateSunPosition();

void WCSTransMenu(GLint transOption) {}
void VCSTransMenu(GLint transOption) {}
void MCSTransform(GLint) {}
void WCSTransform(GLint) {}
void VCSTransform(GLint) {}
void cullMenu(GLint option) {}
void lightMenu(GLint option) {}
void lightTransform(GLint) {}
void shadeMenu(GLint option) {}
//void animateMenu(GLint option) {}
void curveSurfaceMenu(GLint option) {}
void move() {}

// Sun position and color
GLfloat sunPosition[] = { 0.0f, 10.0f, 0.0f, 0.0f };  // Directional light
GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };

Car car(0.0f, 10.0f, 0.1f); // Starting at (0, 10) with a speed of 0.1
bool carAnimationEnabled = false; // Initially, car animation is disabled


GLuint waterTexture;

bool sunEnabled = true;  // Initially, the sun is enabled

bool cubePositions[20][20] = {false};
//cube cubesBuilt[20][20];
//cube blackSquares[20][20];
StopSign stopSign(10.0f, 0.0f, 10.0f);  // New position at (10, 10)

cube grayCube(0, 0);  // Adjust the grid position of the gray cube
rectangle testRec(0,1);
std::list<rectangle*> rectangleList;

//cube testCube(2, 2);  // Adjust the grid position of the gray cubeb
std::list<cube*> objlist;

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

    stopSign.render();

}

void updateCamera() {
    // Move the whole scene down and back to be in the view of the camera
    glTranslatef(0.0f, -5.0f, -cameraDistance);

    // Apply rotations around the origin (center of the grid)
    glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f); // Rotate the camera around the X-axis
    glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f); // Rotate the camera around the Y-axis

    // Move the camera to look at the center of the grid
    glTranslatef(-10.0f, 0.0f, -10.0f);
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	updateCamera();
    updateSunPosition();  // Add this line before drawing anything

	drawGrid();
	//testCube.draw();

//	for (int i = 0; i < 20; ++i) {
//		for (int j = 0; j < 20; ++j) {
//			if(cubePositions[i][j] == true)
//			{
//				                //blackSquares[i][j].draw();
//
//			}
//		}
//	}
	grayCube.draw();

	for (std::list<cube*>::iterator it = objlist.begin(); it != objlist.end(); ++it) {
		    (*it)->draw();
		}


	for (std::list<rectangle*>::iterator it = rectangleList.begin(); it != rectangleList.end(); ++it) {
			    (*it)->draw();
			}

	if (carAnimationEnabled) {
	        car.update();
	    }
	    car.draw();
	// Draw the gray cube
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
    cube* blueCube;
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
    case '-':
        cameraDistance += 2.0f; // zoom out
        if (cameraDistance > 100.0f) { // set a max distance to prevent going too far
            cameraDistance = 100.0f;
        }
        break;
    case '=':
            cameraDistance -= 2.0f; // Zoom in
            if (cameraDistance < 5.0f) { // Set a minimum distance to prevent getting too close
                cameraDistance = 5.0f;
            }
            break;
	case 'b':
		blueCube = new cube(grayCube.getX(), grayCube.getY()); // Assuming grayCube is the instance of the existing gray cube
				//blueCube->setColor(0.0f, 0.0f, 1.0f); // Set color to blue
		objlist.push_back(blueCube); // Store the cube in objlist
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
	 case 'v':
	        // Create a new rectangle at the grayCube's position
	        rectangle* newRectangle = new rectangle(grayCube.getX(), grayCube.getY());
	        rectangleList.push_back(newRectangle);
	        break;

	}

	glutPostRedisplay();
}

void reset() {
    // Reset camera settings
    cameraAngleX = 40.0f;
    cameraAngleY = 0.0f;
    cameraDistance = 35.0f;

    // Reset sun settings
    sunEnabled = true;
    sunPosition[0] = 0.0f;
    sunPosition[1] = 10.0f;
    sunPosition[2] = 0.0f;
    sunPosition[3] = 0.0f; // Assuming the w component is intentionally 0 for directional light

    // Reset cube positions or other game state variables
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cubePositions[i][j] = false;
        }
    }

    // Clear the list of cubes built
    for (std::list<cube*>::iterator it = objlist.begin(); it != objlist.end(); ++it) {
        delete *it;  // Delete the dynamically allocated cube
    }
    objlist.clear();  // Clear the list

    for (std::list<rectangle*>::iterator it = rectangleList.begin(); it != rectangleList.end(); ++it) {
            delete *it;  // Delete the dynamically allocated cube
        }
    rectangleList.clear();  // Clear the list

    // If you have objects that need to be reset, do it here
    // Example:
    // grayCube.setPosition(0, 0); // Reset position if there's such a function
    // testCube.setPosition(2, 2); // Same as above

    // Add any other state resets you need here
}

void light() {
    sunEnabled = !sunEnabled;
}


void animateMenu(GLint option) {
    switch (option) {
    case 1:
        carAnimationEnabled = true;
        break;
    case 2:
        carAnimationEnabled = false;
        break;
    }
}

void menu() {
    // Create the main menu and attach menu entries
    GLint main_Menu = glutCreateMenu(mainMenu);
    glutAddMenuEntry("Light", 1);
    glutAddMenuEntry("Reset", 2);
    glutAddMenuEntry("Quit", 3);


    GLint carAnimMenu = glutCreateMenu(animateMenu);
        glutAddMenuEntry("Start Car Animation", 1);
        glutAddMenuEntry("Stop Car Animation", 2);

        // Add the car animation submenu to the main menu
        glutSetMenu(main_Menu);
        glutAddSubMenu("Car Animation", carAnimMenu);
    // Attach the menu to the right button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void timer(int value) {
    // if (carAnimationEnabled) {
    //     car.update();
    // }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(35, 1.0f, 0.01f, 1000);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1, 0.1, 0.3, 1); // darker blue tone

    // Lighting setup
    glEnable(GL_LIGHTING);     // Enable lighting
    glEnable(GL_LIGHT0);       // Enable light #0
    glEnable(GL_COLOR_MATERIAL); // Enable color tracking
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // Set material properties to follow glColor values

    // Set light properties
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

    menu(); // call the menu init function here
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 900);
	glutCreateWindow("City Builder");
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0); // Start the timer for the first time
	init();
	glutMainLoop();
	return 0;
}
