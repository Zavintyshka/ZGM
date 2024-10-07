#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
 
namespace ZGM {
	class ZGM_API Logger
	{
	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_clientLogger; };

	};
}


// Core Log Macros
#define ZGM_CORE_CRITICAL(...)		ZGM::Logger::GetCoreLogger()->critical(__VA_ARGS__)
#define ZGM_CORE_ERROR(...)			ZGM::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define ZGM_CORE_WARN(...)			ZGM::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define ZGM_CORE_INFO(...)			ZGM::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define ZGM_CORE_TRACE(...)			ZGM::Logger::GetCoreLogger()->trace(__VA_ARGS__)

// Client Log Macros
#define ZGM_CLIENT_CRITICAL(...)	ZGM::Logger::GetClientLogger()->critical(__VA_ARGS__)
#define ZGM_CLIENT_ERROR(...)		ZGM::Logger::GetClientLogger()->error(__VA_ARGS__)
#define ZGM_CLIENT_WARN(...)		ZGM::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define ZGM_CLIENT_INFO(...)		ZGM::Logger::GetClientLogger()->info(__VA_ARGS__)
#define ZGM_CLIENT_TRACE(...)		ZGM::Logger::GetClientLogger()->trace(__VA_ARGS__)

