#include "zgmpch.h"
#include "Logger.h"



namespace ZGM {
	std::shared_ptr<spdlog::logger> Logger::s_coreLogger;
	std::shared_ptr<spdlog::logger> Logger:: s_clientLogger;

	void Logger::Init() {
		spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^%L%$] [thread %t] %v");
		s_coreLogger = spdlog::stdout_color_mt("ZGM Game Engine");
		s_coreLogger->set_level(spdlog::level::debug);
		ZGM_CORE_INFO("ZGM Core Logger successfully loaded!");

		s_clientLogger = spdlog::stdout_color_mt("App");
		s_clientLogger->set_level(spdlog::level::debug);
		ZGM_CLIENT_INFO("Client Logger successfully loaded!");
	}
}