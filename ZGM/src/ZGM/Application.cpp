#include "zgmpch.h"
#include "Application.h"



namespace ZGM {
	Application::Application()
	{
		m_windowObj = std::make_unique<Window>();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		GLFWwindow* winPtr = m_windowObj->GetWindow();
		while (!glfwWindowShouldClose(winPtr)) {
			glClearColor(0.0f, 0.271f, 0.141f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_windowObj->OnUpdate();
		}
	}
}
