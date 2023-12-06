#ifndef CAR_HPP
#define CAR_HPP

#include <GL/glut.h>  // Include this if GLuint is not recognized

class Car {
public:
    Car(float startX, float startY, float startSpeed);
    void setTexture(GLuint texID);  // Ensure parameter type is GLuint
    void draw();
    void update();
    void setSpeed(float newSpeed);

private:
    float x, y;
    float speed;
    GLuint textureID;  // Make sure this is declared
};

#endif // CAR_HPP
