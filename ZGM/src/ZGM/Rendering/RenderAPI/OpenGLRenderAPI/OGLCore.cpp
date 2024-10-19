#include "zgmpch.h"
#include "OGLCore.h"

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLCheckError(const char* funcName, const char* filename, int line) {
    while (GLenum error = glGetError()) {
        ZGM_CORE_ERROR("[OpenGL Error] Error Code: {0}\n{1}, {2}, {3}", error, filename, funcName, line);
        return false;
    }
    return true;
}