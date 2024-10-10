#pragma once
#include "Core.h"
#include "Graphics/WindowAPI.h"

namespace ZGM {
	class ZGM_API Application
	{
	private:
		std::unique_ptr<Window> m_windowObj;
		bool m_running = true;
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowCloseEvent& event);
	};



	// Client func
	Application* CreateApplication();
}
