#pragma once

#ifdef TICK_PLATFORM_WINDOWS
	#ifdef TICK_BUILD_DLL
		#define TICK_API __declspec(dllexport)
	#else 
		#define TICK_API __declspec(dllimport)
	#endif
#else
	#error Only supporting Windows at the moment!
#endif