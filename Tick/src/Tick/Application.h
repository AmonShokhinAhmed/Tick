#pragma once

#include "Core.h"

/*Application class. The user has to inherit from this class to create an application. 
And then define CreateApplication to return an instance of their custom child application type.*/
namespace Tick {
	class TICK_API Application
	{
	public:

		Application();
		virtual ~Application();

		//Tick calls Run() to start the game loop. 
		void Run();
	};
	Application* CreateApplication();
}

