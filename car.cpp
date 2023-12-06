// #include "car.hpp"

// #include <GL/glut.h>

// // Declare global variables
// extern Car car; // Declare as extern if in a header file
// extern bool carAnimationEnabled; // Declare as extern if in a header file

// // Function prototypes
// void animateMenu(GLint option);

// // Global car object
// Car car(0.0f, 10.0f, 0.1f); // Starting at (0, 10) with a speed of 0.1

// bool carAnimationEnabled = false;

// void animateMenu(GLint option) {
//     switch (option) {
//     case 1:
//         carAnimationEnabled = true;
//         break;
//     case 2:
//         carAnimationEnabled = false;
//         break;
//     }
//     glutPostRedisplay();
// }
#include "car.hpp" // Make sure this matches the actual name of your header file
#include <GL/glut.h>

Car::Car(float startX, float startY, float startSpeed) : x(startX), y(startY), speed(startSpeed) {
    // Constructor implementation
}

void Car::draw() {
    // Draw method implementation
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glTranslatef(x, 0.2, y); // Translate to car's position
    glutSolidCube(0.5); // Draw a cube representing the car
    glPopMatrix();
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
