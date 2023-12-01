#include <iostream>
#include <GL/glut.h>

void testCube() {
    glColor3f(1, 1, 1);
    glutSolidCube(0.4);
}

void drawGrid() {
    glColor3f(1, 1, 1);
    glLineWidth(1);

    for (int i = 0; i < 40; ++i) {
        glPushMatrix();

        if (i < 20) {
            glTranslatef(0, 0, i);
        } else {
            glTranslatef(i - 20, 0, 0);
            glRotatef(-90, 0, 1, 0);
        }

        glBegin(GL_LINES);
        glVertex3f(0, -0.1, 0);
        glVertex3f(19, -0.1, 0);
        glEnd();

        glPopMatrix();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-13, 0, -35);
    glRotatef(40, 1, 1, 0);

    drawGrid();
    // testCube();

    glutSwapBuffers();
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
    init();
    glutMainLoop();
    return 0;
}
