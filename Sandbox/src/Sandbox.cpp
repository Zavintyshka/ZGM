#include "ZGM.h"


#define print(x) std::cout << x << std::endl;

class Sandbox : public ZGM::Application {
public:
	Sandbox() {

	};

	~Sandbox() {

	};
	
	void Run() override{
		ZGM::Window win(WindowProperties("My Game", 640, 480), OpenGLProperties(3,3));
		while (true) {

		}
	}
};


ZGM::Application* ZGM::CreateApplication() {
	return new Sandbox();
}



