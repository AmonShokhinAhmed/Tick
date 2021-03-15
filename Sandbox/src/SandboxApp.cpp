#include "Tick.h"

//Inherting the Tick::Application class to create an application
class Sandbox : public Tick::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

//Defining Tick::CreateApplication so Tick knows how to create the custom Sanbox application
Tick::Application* Tick::CreateApplication() {
	Sandbox* sandbox = new Sandbox();
	LOG_INFO("Sandbox was created!");
	return sandbox;
}