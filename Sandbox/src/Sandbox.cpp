#include "ZGM.h"
#include <iostream>

class Sandbox : public ZGM::Application {
public:
	Sandbox() {

	};

	~Sandbox() {

	};
	
	void Run() override{
		while (true) {

		}
	}
};


ZGM::Application* ZGM::CreateApplication() {
	return new Sandbox();
}



