// Cube.cpp
#include "cube.hpp"

cube::cube(float x, float y) : posX(x), posY(y) {}

void cube::draw() {
    glPushMatrix();

    glTranslatef(posX+.5, 0.5, posY+.5);  // Adjust the y-coordinate to lift the cube above the grid
    glColor3f(0.5, 0.5, 0.5);  // Gray color for the cube

    // Adjust the scale to make the cube bigger (e.g., scale by 2.5 in all dimensions)
     glScalef(2.5, 2.5, 2.5);

    glutSolidCube(0.4);

    glPopMatrix();
}
void cube::move(float deltaX, float deltaY) {
    posX += deltaX;
    posY += deltaY;
}


float cube::getX() const {
    return posX;
}

float cube::getY() const {
    return posY;
}
