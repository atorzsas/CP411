#include "rectangle.hpp"

rectangle::rectangle(float x, float y) : posX(x), posY(y) {}

void rectangle::draw() {
	 glPushMatrix();
	    // Adjust the position to align with the grid
	    // Assuming posX and posY represent the center of the rectangle
	    // Move up by 1.0f units to align the base with the grid
	    glTranslatef(posX + 0.5f, 1.0f, posY + 0.5f);

	    glColor3f(0.7, 0.7, 0.7); // Color of the rectangle

	    // Drawing the rectangle as a scaled cube
	    glScalef(1, 2, 1);  // Scaling to make it 2 units tall
	    glutSolidCube(1);
	    glPopMatrix();
}

void rectangle::move(float deltaX, float deltaY) {
    posX += deltaX;
    posY += deltaY;
}
float rectangle::getX() const {
    return posX;
}

float rectangle::getY() const {
    return posY;
}
