#include "ZGM.h"


#define print(x) std::cout << x << std::endl;

class Sandbox : public ZGM::Application {
public:
	Sandbox() {
		m_layerStack.InsertLayer("Overlay Lower", true);
		m_layerStack.InsertLayer("Graphics", false);
		m_layerStack.InsertLayer("Effects", false);
		m_layerStack.InsertLayer("Overlay Upper", true);
	};

	~Sandbox() {

	};
};


ZGM::Application* ZGM::CreateApplication() {
	return new Sandbox();
}



