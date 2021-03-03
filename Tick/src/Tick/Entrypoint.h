#pragma once
#include <stdio.h>

#ifdef TICK_PLATFORM_WINDOWS

extern Tick::Application* Tick::CreateApplication();

int main(int argc, char** argv) 
{
	printf("Tick Engine\n");
	auto app = Tick::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif