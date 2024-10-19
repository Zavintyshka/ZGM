#pragma once
#include "WindowAPI.h"

#ifdef ZGM_PLATFORM_WINDOWS
extern ZGM::Application* ZGM::CreateApplication();

int main(int argc, char** argv) {
	ZGM::Logger::Init();
	ZGM::Application* app = ZGM::CreateApplication();
	ZGM_CLIENT_INFO("Client App started!");
	app->Run();
	delete app;
	}
#endif
