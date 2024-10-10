#pragma once
#include "Core.h"
#include "Graphics/WindowAPI.h"

namespace ZGM {
	class ZGM_API Application
	{
	private:
		std::unique_ptr<Window> m_windowObj;
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// Client func
	Application* CreateApplication();
}
