#include "ZGM.h"

class DebugLayer : public ZGM::Layer {
private:
	DebugGUI m_debugGUI;
public:
	DebugLayer(const char* name, bool isOverlay, GLFWwindow* windowPtr)
		: Layer(name, isOverlay), m_debugGUI(windowPtr, "#version 460", 1.5)
	{};
	~DebugLayer() override {};

	void OnEvent(ZGM::Event& event) override {
		ZGM::DispatchEvent dispatcher(event);
		dispatcher.Dispatch<ZGM::MouseMovedEvent>([this](ZGM::MouseMovedEvent& event) {
			return this->m_debugGUI.OnMouseMoved(event);
			});

		dispatcher.Dispatch<ZGM::MouseButtonPressedEvent>([this](ZGM::MouseButtonPressedEvent& event) {
			return this->m_debugGUI.OnMousePressed(event);
			});

		dispatcher.Dispatch<ZGM::MouseButtonReleasedEvent>([this](ZGM::MouseButtonReleasedEvent& event) {
			return this->m_debugGUI.OnMouseReleased(event);
			});

		dispatcher.Dispatch<ZGM::MouseScrolledEvent>([this](ZGM::MouseScrolledEvent& event) {
			return this->m_debugGUI.OnMouseScrolled(event);
			});

		ZGM::Layer::OnEvent(event);
	};

	void OnUpdate() override {
		m_debugGUI.NewFrame();

		m_debugGUI.Begin("Hello, ImGui!");
		if (m_debugGUI.Button("Click me")) {
			m_debugGUI.Text("Button clicked!");
		}
		m_debugGUI.End();
	};

	void OnRender() override {
		m_debugGUI.Render();
	}
};



class Sandbox : public ZGM::Application {
public:
	Sandbox() {
		DebugLayer* dl = new DebugLayer("ImGUI Debug", true, m_windowObj->GetWindow());
		m_layerStack.InsertLayer(dl);
	};

	~Sandbox() {

	};
};


ZGM::Application* ZGM::CreateApplication() {
	return new Sandbox();
}



