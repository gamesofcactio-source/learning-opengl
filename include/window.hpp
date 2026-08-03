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
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      std::cout << "Failed to initialize GLAD\n";
      return -1;
    }

    glfwSetFramebufferSizeCallback(window, s_framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
      // input
      processInput();

      // rendering
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      // check and call events and swap the buffer
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 1;
  }
};
