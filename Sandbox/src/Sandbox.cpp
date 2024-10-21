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

	void OnEvent(ZGM::Event& event) override {

	}

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
		
		//m_debugGUI.MakeViewport();
		//m_debugGUI.Begin("Explorer");
		//m_debugGUI.Text("HelloWorld.txt");
		//m_debugGUI.Text("MyFile.txt");
		//m_debugGUI.Text("main.cpp");
		//m_debugGUI.End();

		//m_debugGUI.Begin("Object Properties");
		//m_debugGUI.Text("Speed:");
		//m_debugGUI.Text("Position:");
		//m_debugGUI.Text("Opacity:");
		//m_debugGUI.End();

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

	void OnEvent(ZGM::Event& event) override{

	}

	void OnUpdate() override {
		// Input Polling
		//MousePosition mousePos = m_inputPollingObj->GetMousePosition();
		//ZGM_CLIENT_INFO("Check Mouse Position through input polling: ({0}, {1})", mousePos.xPos, mousePos.yPos);
		//ZGM_CLIENT_INFO("Is 'Q' pressed: {0}", m_inputPollingObj->IsKeyPressed(ZGM_KEY_Q));
	};
};


class SquareLayer : public ZGM::Layer {
private:
	Render::VertexArray* vertexArray;
	Render::BufferLayout* bufferLayout;
	Render::Texture* texture;

	// Renderer
	Render::IndexBuffer* indexBuffer;
	Render::VertexBuffer* vertexBuffer;
	Render::Shader* shader;
	Render::Renderer* renderer;

public:
	SquareLayer(const char* name, bool isOverlay)
		: ZGM::Layer(name, isOverlay) 
		{
			// 1. Vertex Array
			vertexArray = new Render::VertexArray();

			// 2. Vertex Buffer
			using Vertex = Render::Vertex;

			const Vertex vertices[4] = {
				{-0.5f, -0.5f, 0.0f, 1.0f,		0.0f, 0.0f},
				{0.5f,	-0.5f, 0.0f, 1.0f,		1.0f, 0.0f},
				{0.5f,	 0.5f, 0.0f, 1.0f,		1.0f, 1.0f},
				{-0.5f,  0.5f, 0.0f, 1.0f,		0.0f, 1.0f}
			};

			vertexBuffer = new Render::OGLVertexBuffer(vertices, 4);
			// 3. Buffer Layout + Init

			bufferLayout = new Render::BufferLayout();
			bufferLayout->Push(GL_FLOAT, 4, 6);
			bufferLayout->Push(GL_FLOAT, 2, 6);
			// 4. Vertex Array Init
			vertexArray->AddBuffer(*(Render::OGLVertexBuffer*)vertexBuffer, *bufferLayout);
			// 5. Index Buffer
			unsigned int indecis[6]
			{
				0,1,2,
				0,3,2
			};
			indexBuffer = new Render::OGLIndexBuffer(indecis, 6);
			// 6. Shader + Init
			shader = (new Render::OGLShader("res/shader/VertexShader.shader", "res/shader/FragmentShader.shader"));
			shader->Link();

			// 7. Texture
			texture = new Render::Texture("res/textures/ender.png");

			// 8. Bind
			shader->Bind();
			vertexArray->BindVertexArray();
			vertexBuffer->Bind();
			indexBuffer->Bind();

			// 9. Texture Setup
			texture->Bind(0);
			shader->SetUniform1i("u_texture", 0);

			renderer = new Render::OGLRenderer();
		}

	void OnRender() override {

		renderer->DrawElements();
	}

	void OnEvent(ZGM::Event& event) override {

	}

	~SquareLayer() {
		delete vertexBuffer;
	}


};

class Sandbox : public ZGM::Application {
public:
	Sandbox() {
		DebugLayer* dl = new DebugLayer("ImGUI Debug", true, m_windowObj->GetWindow());
		InputPollingLayer* ipl = new InputPollingLayer("Input Polling", "true", m_windowObj->GetWindow());
		SquareLayer* sl = new SquareLayer("Square", false);
		m_layerStack.InsertLayer(dl);
		m_layerStack.InsertLayer(ipl);
		m_layerStack.InsertLayer(sl);
	};

	~Sandbox() {

	};
};


ZGM::Application* ZGM::CreateApplication() {
	return new Sandbox();
}



