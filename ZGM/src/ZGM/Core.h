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
