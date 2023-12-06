#include "car.hpp" // Make sure this matches the actual name of your header file
#include <GL/glut.h>

Car::Car(float startX, float startY, float startSpeed) : x(startX), y(startY), speed(startSpeed) {
    // Constructor implementation
}

void Car::setTexture(GLuint texID) {
    textureID = texID;
}

void Car::draw() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); // Normally you'd use white to show the texture
    glTranslatef(x, 0.2, y); // Translate to car's position

    // Car's bottom
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.0, -0.5); // Bottom Left
    glTexCoord2f(1.0, 0.0); glVertex3f(0.5, 0.0, -0.5);  // Bottom Right
    glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.0, 0.5);   // Top Right
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.0, 0.5);  // Top Left
    glEnd();

    // Car's top - adjust y value to raise the top
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 1.0, -0.5); // Bottom Left
    glTexCoord2f(1.0, 0.0); glVertex3f(0.5, 1.0, -0.5);  // Bottom Right
    glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 1.0, 0.5);   // Top Right
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 1.0, 0.5);  // Top Left
    glEnd();

    // ... Add other sides of the car similarly with appropriate texture coordinates ...

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}


void Car::update() {
    // Update method implementation
    x += speed; // Move car
    // Boundary check and reverse direction if necessary
    if (x > 20 || x < 0) {
        speed = -speed;
        x += speed;
    }
}

void Car::setSpeed(float newSpeed) {
    // setSpeed method implementation
    speed = newSpeed;
}

