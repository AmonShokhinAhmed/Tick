#pragma once


//Defines necessary for cross compilation and DLL usage
#ifdef TICK_PLATFORM_WINDOWS
	//defining TICK_API to use the appropriate attribute syntax depending on whether the dll is build (with the TICK_BUILD_DLL compiler flag enabled) or linked in a game project.
	#ifdef TICK_BUILD_DLL
		#define TICK_API __declspec(dllexport)
	#else 
		#define TICK_API __declspec(dllimport)
	#endif
#else
	#error Only supporting Windows at the moment!
#endif