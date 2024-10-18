#include "zgmpch.h"
#include "OpenGLContext.h"


namespace ZGM {
	OpenGLContext::OpenGLContext(GLFWwindow* window)
	: m_windowPtr(window) {}

	bool OpenGLContext::Init(){
		glfwMakeContextCurrent(m_windowPtr);
		return true;
	}

	void OpenGLContext::SwapBuffers(){
		glfwSwapBuffers(m_windowPtr);
	}

	bool OpenGLContext::VSync(bool isEnable){
		if (isEnable) {
			glfwSwapInterval(1);
			return true;
		}
		else {
			return false;
		}
			
	}
}