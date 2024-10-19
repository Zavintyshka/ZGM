#pragma once
#include "ZGM/Core.h"
#include <Glfw/glfw3.h>

struct MousePosition {
	float xPos, yPos;
};


namespace ZGM {
	class ZGM_API Input {
	private:
		GLFWwindow* m_windowPtr;
	public:
		Input(GLFWwindow* windowPtr);
		bool IsKeyPressed(int keyCode);
		bool IsMouseButtonPressed(int mouseButton);
		MousePosition GetMousePosition();
	};
}