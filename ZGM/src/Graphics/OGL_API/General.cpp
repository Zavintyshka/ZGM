#include "zgmpch.h"
#include "General.h"

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLCheckError(const char* funcName, const char* filename, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] Error Code: " << error << std::endl << filename << ", " << funcName << ", " << line << std::endl;
        return false;
    }
    return true;
}