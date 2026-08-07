# GLAD
Since there are many different versions of OpenGL drivers, the location of most of its functions is not known at compile-time and needs to be queried at run-time. It is then the task of the developer to retrieve the location of the functions he/she needs and store them in function pointers for later use. However this all can be avoided with the help of GLAD library.

# Clear
Fill an entire graphics buffer with a known value before rendering

# Why must GLAD come first?
glad.h provides all the OpenGL declarations (glClear, glViewport, GL_COLOR_BUFFER_BIT)
glfw3.h sometimes includes the system's OpenGL headers if GLAD hasn't already been included

# Buffer
Front Buffer  ---> Visible on the screen
Back Buffer   ---> Hidden

# Graphic pipeline
In OpenGL everything is in 3D space, but the screen or window is a 2D array of pixels so a large part of OpenGL's work is about transforming all 3D coordinates to 2D pixels that fit on your screen. 

The process of transforming 3D coordinates to 2D pixels is managed by the graphics pipeline of OpenGL. The graphics pipeline can be divided into two large parts: the first transforms your 3D coordinates into 2D coordinates and the second part transforms the 2D coordinates into actual colored pixels.

Graphics cards of today have thousands of small processing cores to quickly process your data within the graphics pipeline. The processing cores run small programs on the GPU for each step of the pipeline. These small programs are called shaders. 

Shaders are written in the OpenGL Shading Language (GLSL)

# How a triangle is made
As input to the graphics pipeline we pass in a list of three 3D coordinates that should form a triangle in an array here called Vertex Data
 
In order for OpenGL to know what to make of your collection of coordinates and color values OpenGL requires you to hint what kind of render types you want to form with the data. Do we want the data rendered as a collection of points, a collection of triangles or perhaps just one long line? Those hints are called primitives


