#include "ZGM.h"

class DebugLayer : public ZGM::Layer {
private:
	DebugGUI m_debugGUI;
	Render::Camera& camera = Render::Camera::CreateCamera(1920.0f, 1080.0f);
	float m_cameraPosX = camera.GetPos().x, m_cameraPosY = camera.GetPos().y;

public:
	DebugLayer(const char* name, bool isOverlay, GLFWwindow* windowPtr)
		: Layer(name, isOverlay), m_debugGUI(windowPtr, "#version 460", 1.5)
	{
		m_debugGUI.GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		m_debugGUI.GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	};
	~DebugLayer() override {};
	
	void OnEvent(ZGM::Event& event) override {
		ZGM::DispatchEvent dispatcher(event);
		dispatcher.Dispatch<ZGM::KeyPressedEvent>([this](ZGM::KeyPressedEvent& event) {
			return this->OnKeyClicked(event);
			});
	}

	void OnUpdate() override {
		m_debugGUI.NewFrame();

		m_debugGUI.Begin("Camera Propeties");
		m_debugGUI.Text("Camera Position:");

		m_debugGUI.Text(std::to_string(m_cameraPosX).c_str());
		m_debugGUI.Text(std::to_string(m_cameraPosY).c_str());
		m_debugGUI.SliderF("CameraPosX", &m_cameraPosX, -400.0f, 400.0f);
		m_debugGUI.SliderF("CameraPosY", &m_cameraPosY, -400.0f, 400.0f);
		m_debugGUI.End();

		UpdateCameraData();
	};

	void OnRender() override {
		m_debugGUI.Render();
	}

	bool OnKeyClicked(ZGM::KeyPressedEvent event) {
		int keyCode = event.GetKeyCode();

		switch (keyCode) {
			case ZGM_KEY_UP:
			case ZGM_KEY_W:
				m_cameraPosY += 20;
				break;

			case ZGM_KEY_DOWN:
			case ZGM_KEY_S:
				m_cameraPosY -= 20;
				break;

			case ZGM_KEY_LEFT:
			case ZGM_KEY_A:
				m_cameraPosX -= 20;
				break;

			case ZGM_KEY_RIGHT:
			case ZGM_KEY_D:
				m_cameraPosX += 20;
				break;
		}	
		UpdateCameraData();
		event.m_isEventHandled = true;
		return true;
	};
private:
	void UpdateCameraData() {
		glm::vec2 newCameraPos = glm::vec2(m_cameraPosX, m_cameraPosY);
		camera.SetPos(newCameraPos);
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
	Render::Texture* texture;

	// Renderer
	Render::VertexArray* vertexArray;
	Render::VertexBufferLayout* bufferLayout;
	Render::IndexBuffer* indexBuffer;
	Render::VertexBuffer* vertexBuffer;
	Render::Shader* shader;
	Render::Renderer* renderer;

	// Camera
	Render::Camera& camera = Render::Camera::CreateCamera(1920.0f, 1080.0f);
	glm::mat4 vpMatrix = glm::mat4(1.0f);
	glm::mat4 modelMatrix = glm::mat4(1.0f);


public:
	SquareLayer(const char* name, bool isOverlay)
		: ZGM::Layer(name, isOverlay)
		{
			// 1. Vertex Array
			vertexArray = Render::GeometryFabric::CreateVertexArray();

			// 2. Vertex Buffer
			using Vertex = Render::Vertex;

			const Vertex vertices[4] = {
				{860.0f,	440.0f,		0.0f, 1.0f,		0.0f, 0.0f},
				{1060.0f,	440.0f,		0.0f, 1.0f,		1.0f, 0.0f},
				{1060.0f,	640.0f,		0.0f, 1.0f,		1.0f, 1.0f},
				{860.0f,	640.0f,		0.0f, 1.0f,		0.0f, 1.0f}
			};

		
			vertexBuffer = Render::GeometryFabric::CreateVertexBuffer(vertices, 4);
			// 3. Buffer Layout + Init

			bufferLayout = Render::GeometryFabric::CreateVertexBufferLayout();
			bufferLayout->Push(GL_FLOAT, 4, true, 6);
			bufferLayout->Push(GL_FLOAT, 2, true, 6);
			// 4. Vertex Array Init
			vertexArray->AddBuffer(*vertexBuffer, *bufferLayout);
			// 5. Index Buffer
			unsigned int indecis[6]
			{
				0,1,2,
				0,3,2
			};
			indexBuffer = Render::GeometryFabric::CreateIndexBuffer(indecis, 6);
			// 6. Shader + Init
			shader = Render::ShaderFabric::CreateShader("res/shader/VertexShader.shader", "res/shader/FragmentShader.shader");
			shader->Link();

			// 7. Texture
			texture = new Render::Texture("res/textures/ender.png");

			// 8. Bind
			shader->Bind();
			vertexArray->Bind();
			vertexBuffer->Bind();
			indexBuffer->Bind();

			// 9. Texture Setup
			texture->Bind(0);
			shader->SetUniform1i("u_texture", 0);

			renderer = new Render::OGLRenderer();
		}	

	void OnUpdate() override {
		vpMatrix = camera.GetVPMatrix();
		// Model Matrix
	}


	void OnRender() override {
		renderer->BeginScene();
		shader->Bind();
		vertexArray->Bind();
		shader->SetUniformMat4f("u_VP", vpMatrix); // VP from Camera Obj
		shader->SetUniformMat4f("u_Model", modelMatrix); // Define Here
		renderer->Submit();
		renderer->EndScene();
	}


	~SquareLayer() {
		delete vertexBuffer;
	}


};

class Sandbox : public ZGM::Application {
public:
	Sandbox() {
		SquareLayer* sl = new SquareLayer("Square", false);
		DebugLayer* dl = new DebugLayer("ImGUI Debug", true, m_windowObj->GetWindow());
		InputPollingLayer* ipl = new InputPollingLayer("Input Polling", "true", m_windowObj->GetWindow());
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



