#pragma once

// OpenGL
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#define print(x) std::cout << x << std::endl
#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCall(drawCall) GLClearError();\
    drawCall;\
    ASSERT(GLCheckError(#drawCall, __FILE__, __LINE__))


void GLClearError();
bool GLCheckError(const char* funcName, const char* filename, int line);