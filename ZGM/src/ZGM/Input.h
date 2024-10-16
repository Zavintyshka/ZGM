#pragma once
#include "ZGM/Core.h"
#include "Graphics/OGL_API/General.h"

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