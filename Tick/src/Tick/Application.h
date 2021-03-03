#pragma once

#include "Core.h"
namespace Tick {
	class TICK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}

