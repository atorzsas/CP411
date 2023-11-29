//Nothing here just yet
#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Grid {
public:
    Grid(int slices);
    void render();

private:
    GLuint vao;
    GLuint length;
    std::vector<glm::vec3> vertices;
    std::vector<glm::uvec4> indices;
};
