#pragma once

#include "ZGM/Core.h"
#include "OGLCore.h"
#include "ZGM/Logger.h"

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

	void MakeViewport();
	bool Begin(const char* title);
	bool Button(const char* title);
	void Text(const char* text);
	void SliderF(const char* label, float* value, float value_min, float value_max);
	void End();

public:
	bool OnMouseMoved(ZGM::MouseMovedEvent& event);
	bool OnMousePressed(ZGM::MouseButtonPressedEvent& event);
	bool OnMouseReleased (ZGM::MouseButtonReleasedEvent& event);
	bool OnMouseScrolled (ZGM::MouseScrolledEvent& event);
};