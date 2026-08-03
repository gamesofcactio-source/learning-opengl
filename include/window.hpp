#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

struct window
{
  constexpr static int s_width{800};
  constexpr static int s_height{600};
  GLFWwindow* window{nullptr};

  static void s_framebuffer_size_callback(GLFWwindow* window, int width, int height)
  {
    // telling OpenGL the size of the window
    glViewport(0, 0, width, height);
  }

  void processInput()
  {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {

      glfwSetWindowShouldClose(window, 1);
    }
  }

  int createWindow()
  {

    if (!glfwInit())
    {

      std::cout << "failed to initialize";
      return -1;
    }
    // creates an OpenGL 3.3 context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // there are two OpenGL profile
    // 1. GLFW_OPENGL_CORE_PROFILE(mordern feature)
    // 2. GLFW_OPENGL_COMPAT_PROFILE(mordern + old feature)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(s_width, s_height, "Learning-OpenGL", nullptr, nullptr);
    if (window == nullptr)
    {

      std::cout << "failed to create GLFW window";
      glfwTerminate();
      return -1;
    }
    // tells OpenGL to which window to use
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {

      std::cout << "Failed to initialize GLAD\n";
      return -1;
    }

    // When the framebuffer size change "s_framebuffer_size_callback" get called
    glfwSetFramebufferSizeCallback(window, s_framebuffer_size_callback);

    // render loop
    while (!glfwWindowShouldClose(window))
    {

      // input
      processInput();

      // rendering
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

      // notice we don't pass any GLFWwindow* as parameter as in line 55 we already have told OpenGL to use this window
      // take flag as the parameter
      // GL_COLOR_BUFFER_BIT clear the color buffer
      glClear(GL_COLOR_BUFFER_BIT);

      // check and call events and swap the buffer
      glfwSwapBuffers(window);
      glfwPollEvents(); // check if any event is triggered like - keyboard/mouse inputs
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 1;
  }
};
