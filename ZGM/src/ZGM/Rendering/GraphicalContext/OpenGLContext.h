#pragma once
#include "Context.h"

#include "GLAD/glad.h"
#include <GLFW/glfw3.h>

namespace ZGM {
	class OpenGLContext : public Context {
	private:
		GLFWwindow* m_windowPtr;
	public:
		OpenGLContext(GLFWwindow* window);
		bool Init() override;
		void SwapBuffers() override;
		bool VSync(bool isEnable) override;
	};
}
