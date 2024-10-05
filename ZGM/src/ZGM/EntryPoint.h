#pragma once

#ifdef ZGM_PLATFORM_WINDOWS
extern ZGM::Application* ZGM::CreateApplication();

int main(int argc, char** argv) {
	ZGM::Application* app = ZGM::CreateApplication();
	std::cout << "Init ZGM\n";
	app->Run();
	delete app;
	}
#endif