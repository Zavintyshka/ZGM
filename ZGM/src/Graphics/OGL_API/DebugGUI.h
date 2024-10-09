#pragma once

#include "ZGM/Core.h"
#include "general.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"


class ZGM_API DebugGUI {
public:
	DebugGUI(GLFWwindow* window, const char* OpenGLVersion, float scale);
	~DebugGUI();
	
	void NewFrame() const;
	void Render() const;
	const ImGuiIO& GetIO() const;
};