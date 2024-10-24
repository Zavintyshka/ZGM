#include "zgmpch.h"
#include "Application.h"





namespace ZGM {
	Application::Application()
		: m_windowObj(std::make_unique<Window>())
	{
		m_renderCommand = Render::RendererFabric::CreateRenderCommand();
		m_windowObj->SetEventCallbackFN(BIND_EVENT_CALLBACK(Application::OnEvent));
		m_inputPolling = new Input(m_windowObj->GetWindow());
		m_camera.Initialize((float)m_windowObj->GetWidth(), (float)m_windowObj->GetHeight());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		GLFWwindow* winPtr = m_windowObj->GetWindow();
		glm::vec4 clearColor(0.0f, 0.271f, 0.141f, 1.0f);

		while (m_running) {
			m_renderCommand->SetClearColor(clearColor);
			m_renderCommand->Clear();

			// Layer OnUpdate
			for (auto it = m_layerStack.Begin(); it != m_layerStack.End(); it++) {
				(*it)->OnUpdate();
			}

			// Layer OnRender
			for (auto it = m_layerStack.Begin(); it != m_layerStack.End(); it++) {
				(*it)->OnRender();
			}

			m_windowObj->OnUpdate();
		}

		// API Terminate
	}
	void Application::OnEvent(Event& event)
	{
		DispatchEvent dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_CALLBACK(Application::OnWindowClose));
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
