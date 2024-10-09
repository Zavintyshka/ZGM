#pragma once

#ifdef ZGM_PLATFORM_WINDOWS
	#ifdef ZGM_BUILD_DLL
		#define ZGM_API __declspec(dllexport)
	#else
		#define ZGM_API __declspec(dllimport)
	#endif
#else
	#error ZGM supports only Windows OC
#endif

#ifdef _DEBUG
#define ZGM_ASSERT(exp, successMessage, failedMessage) if (!(exp)) { ZGM_CORE_ERROR("Assertion Failed: {0}", failedMessage); } else { ZGM_CORE_INFO(successMessage); }
#define ZGM_DEBUG_PRINT(msg) std::cout << msg << std::endl
#else
#define ZGM_ASSERT(exp, successMessage, failedMessage) exp
#define ZGM_DEBUG_PRINT(msg)
#endif
