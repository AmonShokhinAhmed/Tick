#pragma once
#include <stdio.h>

#ifdef TICK_PLATFORM_WINDOWS

extern Tick::Application* Tick::CreateApplication();

int main(int argc, char** argv) 
{
	printf("Tick Engine\n");

	Tick::Log::Init();
	LOG_CORE_WARN("warn");
	int a = 5;
	LOG_INFO("Hello! Var={0}", a);
	auto app = Tick::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif