#include "ZGM.h"


class GraphicsLayer : public ZGM::Layer {
public:
	GraphicsLayer(const char* name, bool isOverlay)
		: Layer(name, isOverlay)
	{}
	void OnUpdate() override {

	}

	void OnEvent(ZGM::Event& event) override {
		ZGM_CLIENT_INFO("{0} handled by {1} layer", event.ToString(), GetName());
	}

	~GraphicsLayer() override {

	}
};



class OverlayUpperLayer : public ZGM::Layer {
public:
	OverlayUpperLayer(const char* name, bool isOverlay)
		: Layer(name, isOverlay)
	{}
	void OnUpdate() override {

	}

	void OnEvent(ZGM::Event& event) override {
		ZGM_CLIENT_INFO("{0} handled by {1} layer", event.ToString(), GetName());
	}

	~OverlayUpperLayer() override {

	}
};




class Sandbox : public ZGM::Application {
public:
	Sandbox() {
		GraphicsLayer* gl = new GraphicsLayer("Graphics", false);
		OverlayUpperLayer* ol = new OverlayUpperLayer("OverlayUpper", true);

		m_layerStack.InsertLayer(gl);
		m_layerStack.InsertLayer(ol);

	};

	~Sandbox() {

	};
};


ZGM::Application* ZGM::CreateApplication() {
	return new Sandbox();
}



