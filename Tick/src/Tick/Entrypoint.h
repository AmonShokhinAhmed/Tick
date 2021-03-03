#pragma once
#include <stdio.h>

#ifdef TICK_PLATFORM_WINDOWS

extern Tick::Application* Tick::CreateApplication();

int main(int argc, char** argv) 
{

	Tick::Log::Init();
	LOG_INFO("Welcome to the Tick Engine!");
	auto app = Tick::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif