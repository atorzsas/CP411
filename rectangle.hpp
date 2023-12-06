#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <GL/glut.h>

class rectangle {
public:
	rectangle(float x, float y);
    void draw();
    void move(float deltaX, float deltaY);

    float getX() const;
    float getY() const;
private:
    float posX, posY;
};

#endif // RECTANGLE_HPP
