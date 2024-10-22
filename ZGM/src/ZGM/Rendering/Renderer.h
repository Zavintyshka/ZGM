#pragma once
#include "glm/glm.hpp"


namespace Render {
	class Renderer {
	public:
		virtual void BeginScene() = 0;
		virtual void EndScene() = 0;
		virtual void Submit() = 0;
		virtual void DrawIndexed() = 0;
	};


	class RenderCommand{
	public:
		virtual void Clear() = 0;
		virtual void SetClearColor(glm::vec4& color) = 0;
	};
}