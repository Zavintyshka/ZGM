#include "zgmpch.h"
#include "Application.h"



namespace ZGM {
#define BIND_EVENT_CALLBACK(func) std::bind(&Application::func, this, std::placeholders::_1)
	Application::Application()
	{
		m_windowObj = std::make_unique<Window>();
		m_windowObj->SetEventCallbackFN(BIND_EVENT_CALLBACK(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{


		GLFWwindow* winPtr = m_windowObj->GetWindow();
		while (m_running) {
			glClearColor(0.0f, 0.271f, 0.141f, 1.0f);

			glClear(GL_COLOR_BUFFER_BIT);
			
			// Layer OnUpdate
			for (auto it = m_layerStack.Begin(); it != m_layerStack.End(); it++) {
				//print(it->GetName());
			}

			m_windowObj->OnUpdate();
		}
	}
	void Application::OnEvent(Event& event)
	{
		DispatchEvent dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_CALLBACK(OnWindowClose));
		ZGM_CORE_INFO(event.ToString());

		// Layer OnEvent
		for (auto it = m_layerStack.End(); it != m_layerStack.Begin();) {
			it--;
			if (event.m_isEventHandled)
				break;
			(*it)->OnEvent(event);
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}
}
