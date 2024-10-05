#include "ZGM.h"

class Sandbox : public ZGM::Application {
public:
	Sandbox() {

	};

	~Sandbox() {

	};
};


ZGM::Application* ZGM::CreateApplication() {
	return new Sandbox();
}



