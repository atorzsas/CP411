// Cube.hpp
#ifndef CUBE_HPP
#define CUBE_HPP

#include <GL/glut.h>

class cube {
public:
    cube(float x, float y);
    void draw();
    void move(float deltaX, float deltaY);

    float getX() const;
    float getY() const;
private:
    float posX;
    float posY;
};




#endif // CUBE_HPP
