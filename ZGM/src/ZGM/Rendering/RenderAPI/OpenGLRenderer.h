#pragma once
#include "OpenGLRenderAPI/OGLCore.h"
#include "ZGM/Rendering/Renderer.h"

namespace Render {
	class ZGM_API OGLRenderer: public Renderer {
	private:
	public:
		void BeginScene() override;
		void EndScene() override;
		void Submit() override;
		void DrawIndexed() override;
	};

	class OGLRenderCommand : public RenderCommand {
	public:
		void Clear() override {
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void SetClearColor(glm::vec4& color) override {
			glClearColor(color.r, color.g, color.b, color.a);
		}
	};
}