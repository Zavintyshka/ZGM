#pragma once
#include "glm/glm.hpp"

#include "VertexArray.h"
#include "Shader.h"
#include "ZGM/Rendering/Camera.h"


namespace Render {
	class Renderer {
	public:
		virtual void BeginScene(Camera& camera) = 0;
		virtual void EndScene() = 0;
		virtual void Submit(Shader& shader, VertexArray& vertexArray, unsigned int indexCount) = 0;
		virtual void DrawIndexed() = 0;
	};


	class RenderCommand{
	public:
		virtual void Clear() = 0;
		virtual void SetClearColor(glm::vec4& color) = 0;
	};
}