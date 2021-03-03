#include "Tick.h"

class Sandbox : public Tick::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Tick::Application* Tick::CreateApplication() {
	return new Sandbox();
}