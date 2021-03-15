#pragma once
#include <stdio.h>

//Only works on windows for now
#ifdef TICK_PLATFORM_WINDOWS
	
	//using extern so compiler knows that the definition exists (the user has to define it in their application). 
	extern Tick::Application* Tick::CreateApplication();

	//actual entrypoint for the whole engine
	int main(int argc, char** argv) 
	{

		//Initialising all systems
		//Just logging for now
		Tick::Log::Init();

		LOG_CORE_INFO("Welcome to the Tick Engine!");

		//Creating the application
		auto app = Tick::CreateApplication();

		//Starting the application
		app->Run();

		//clean up
		delete app;
		return 0;
	}
#endif