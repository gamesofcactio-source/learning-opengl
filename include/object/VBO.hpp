#include "../glad/glad.h"
#include <GLFW/glfw3.h>

struct VBO
{
  static void buffer(float pos[], size_t size)
  {
    // vertex buffer
    unsigned int vbo;      // VBO - vertex buffer object
    glGenBuffers(1, &vbo); // generating a buffer and giving us id
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, pos, GL_STATIC_DRAW);
    // 6 * sizeof(float) because we have a array of 6 flaot in include/object/triangle.hpp
  }
};
