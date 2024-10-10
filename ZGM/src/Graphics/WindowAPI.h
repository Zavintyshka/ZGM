#pragma once
#include "ZGM/Core.h"
#include "ZGM/Logger.h"
#include "General.h"

struct WindowProperties {
	const char* title;
	unsigned int width, height;

	WindowProperties(const char* winTitle = "Zavintyshka's Game Engine", unsigned int winWidth = 1920, unsigned int winHeight = 1080)
		: title(winTitle), width(winWidth), height(winHeight) {}
};

struct OpenGLProperties {
	unsigned int majorVersion;
	unsigned int minorVersion;

	OpenGLProperties(unsigned int majorVer = 4, unsigned int minorVer = 5)
		: majorVersion(majorVer), minorVersion(minorVer) {}
};


namespace ZGM {
	class ZGM_API Window {
	private:
		WindowProperties m_winProps;
		OpenGLProperties m_oglProps;
		GLFWwindow* m_window;
	public:
		Window(WindowProperties winProps = WindowProperties(), OpenGLProperties oglProps = OpenGLProperties());
		inline const char* GetTitle() const;
		inline const unsigned int GetWidth() const;
		inline const unsigned int GetHeight() const;
		void OnUpdate();
		GLFWwindow* GetWindow();
	};
}

