#include "zgmpch.h"
#include "Input.h"

namespace ZGM {
	Input::Input(GLFWwindow* windowPtr)
		: m_windowPtr(windowPtr) {}

	bool Input::IsKeyPressed(int keyCode) {
		int keyState = glfwGetKey(m_windowPtr, keyCode);
		return keyState == GLFW_PRESS || keyState == GLFW_RELEASE;
	}
	bool Input::IsMouseButtonPressed(int mouseButton)
	{
		int buttonState = glfwGetMouseButton(m_windowPtr, mouseButton);
		return buttonState == GLFW_PRESS || buttonState == GLFW_RELEASE;
	}
	MousePosition Input::GetMousePosition()
	{
		double xPos, yPos;
		glfwGetCursorPos(m_windowPtr, &xPos, &yPos);
		return MousePosition{ static_cast<float>(xPos), static_cast<float>(yPos) };
	}
}