#include "ZGM.h"


#define print(x) std::cout << x << std::endl;

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



