#pragma once
#include "Core.h"


namespace ZGM {
	class ZGM_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// Client func
	Application* CreateApplication();
}
