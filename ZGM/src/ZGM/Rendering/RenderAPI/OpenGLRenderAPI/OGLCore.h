#pragma once

// API
#include "GLAD/glad.h"
#include <GLFW/glfw3.h>

#include "ZGM/Logger.h"


void GLClearError();
bool GLCheckError(const char* funcName, const char* filename, int line);


#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCall(drawCall) GLClearError();\
    drawCall;\
    ASSERT(GLCheckError(#drawCall, __FILE__, __LINE__))