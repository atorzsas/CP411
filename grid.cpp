// grid.cpp
#include "grid.hpp"
#include <glm/gtc/type_ptr.hpp>

Grid::Grid(int slices) {
    std::vector<glm::vec3> vertices;
    std::vector<glm::uvec2> indices;

    for(int j = 0; j <= slices; ++j) {
        for(int i = 0; i <= slices; ++i) {
            float x = (float)i / (float)slices;
            float y = 0;
            float z = (float)j / (float)slices;
            vertices.push_back(glm::vec3(x, y, z));
        }
    }

    for(int j = 0; j < slices; ++j) {
        for(int i = 0; i < slices; ++i) {
            int row1 =  j    * (slices + 1);
            int row2 = (j + 1) * (slices + 1);

            indices.push_back(glm::uvec2(row1 + i, row1 + i + 1));
            indices.push_back(glm::uvec2(row2 + i + 1, row2 + i));
        }
    }

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), glm::value_ptr(vertices[0]), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(glm::uvec2), glm::value_ptr(indices[0]), GL_STATIC_DRAW);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    length = (GLuint)indices.size() * 2;
}

Grid::~Grid() {
    glDeleteVertexArrays(1, &vao);
}

void Grid::render() {
    glEnable(GL_DEPTH_TEST);

    glBindVertexArray(vao);

    glDrawElements(GL_LINES, length, GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0);

    glDisable(GL_DEPTH_TEST);
}
