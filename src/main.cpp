#include "../include/window.hpp"
#include "../include/object/VBO.hpp"
#include <GLFW/glfw3.h>

int main()
{
  VBO VBO;
  window window;

  window.createWindow(VBO.buffer);
  return 0;
}
