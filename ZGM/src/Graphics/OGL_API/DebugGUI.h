#pragma once

#include "ZGM/Core.h"
#include "general.h"

#include "Events/EventMouse.h"


#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"


class ZGM_API DebugGUI {
public:
	DebugGUI(GLFWwindow* window, const char* OpenGLVersion, float scale);
	~DebugGUI();
	
	static void NewFrame();
	static void Render();
	static ImGuiIO& GetIO();

	bool Begin(const char* title);
	bool Button(const char* title);
	void Text(const char* text);
	void End();

public:
	bool OnMouseMoved(ZGM::MouseMovedEvent& event);
	bool OnMousePressed(ZGM::MouseButtonPressedEvent& event);
	bool OnMouseReleased (ZGM::MouseButtonReleasedEvent& event);
	bool OnMouseScrolled (ZGM::MouseScrolledEvent& event);
};