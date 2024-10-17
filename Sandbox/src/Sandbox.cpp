#include "ZGM.h"

class DebugLayer : public ZGM::Layer {
private:
	DebugGUI m_debugGUI;
public:
	DebugLayer(const char* name, bool isOverlay, GLFWwindow* windowPtr)
		: Layer(name, isOverlay), m_debugGUI(windowPtr, "#version 460", 1.5)
	{
		m_debugGUI.GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		m_debugGUI.GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	};
	~DebugLayer() override {};

	//void OnEvent(ZGM::Event& event) override {
	//	ZGM::DispatchEvent dispatcher(event);
	//	dispatcher.Dispatch<ZGM::MouseMovedEvent>([this](ZGM::MouseMovedEvent& event) {
	//		return this->m_debugGUI.OnMouseMoved(event);
	//		});

	//	dispatcher.Dispatch<ZGM::MouseButtonPressedEvent>([this](ZGM::MouseButtonPressedEvent& event) {
	//		return this->m_debugGUI.OnMousePressed(event);
	//		});

	//	dispatcher.Dispatch<ZGM::MouseButtonReleasedEvent>([this](ZGM::MouseButtonReleasedEvent& event) {
	//		return this->m_debugGUI.OnMouseReleased(event);
	//		});

	//	dispatcher.Dispatch<ZGM::MouseScrolledEvent>([this](ZGM::MouseScrolledEvent& event) {
	//		return this->m_debugGUI.OnMouseScrolled(event);
	//		});

	//	ZGM::Layer::OnEvent(event);
	//};

	void OnUpdate() override {
		m_debugGUI.NewFrame();
		
		m_debugGUI.MakeViewport();
		m_debugGUI.Begin("Explorer");
		m_debugGUI.Text("HelloWorld.txt");
		m_debugGUI.Text("MyFile.txt");
		m_debugGUI.Text("main.cpp");
		m_debugGUI.End();

		m_debugGUI.Begin("Object Properties");
		m_debugGUI.Text("Speed:");
		m_debugGUI.Text("Position:");
		m_debugGUI.Text("Opacity:");
		m_debugGUI.End();

		m_debugGUI.Begin("Terminal");
		m_debugGUI.Text("python3 && print('Hello World!')");
		m_debugGUI.End();
	};

	void OnRender() override {
		m_debugGUI.Render();
	}
};


class InputPollingLayer: public ZGM::Layer {
private:
	ZGM::Input* m_inputPollingObj;
public:
	InputPollingLayer(const char*name, bool isOverlay, GLFWwindow* windowPtr)
	: ZGM::Layer(name, isOverlay) {
		m_inputPollingObj = new ZGM::Input(windowPtr);
	};
	~InputPollingLayer() override {};

	void OnUpdate() override {
		// Input Polling
		MousePosition mousePos = m_inputPollingObj->GetMousePosition();
		ZGM_CLIENT_INFO("Check Mouse Position through input polling: ({0}, {1})", mousePos.xPos, mousePos.yPos);
		ZGM_CLIENT_INFO("Is 'Q' pressed: {0}", m_inputPollingObj->IsKeyPressed(ZGM_KEY_Q));
	};
};


class Sandbox : public ZGM::Application {
public:
	Sandbox() {
		DebugLayer* dl = new DebugLayer("ImGUI Debug", true, m_windowObj->GetWindow());
		InputPollingLayer* ipl = new InputPollingLayer("Input Polling", "true", m_windowObj->GetWindow());
		m_layerStack.InsertLayer(dl);
		m_layerStack.InsertLayer(ipl);
	};

	~Sandbox() {

	};
};


ZGM::Application* ZGM::CreateApplication() {
	return new Sandbox();
}



