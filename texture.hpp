#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glut.h>

class Texture {
public:
    static GLuint loadTexture(const char* filename);
};

#endif // TEXTURE_HPP
