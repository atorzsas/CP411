//Nothing here just yet
// grid.hpp
#ifndef GRID_HPP
#define GRID_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class Grid {
public:
    Grid(int slices);
    ~Grid();

    void render();

private:
    GLuint vao;
    GLuint length;
};

#endif // GRID_HPP
