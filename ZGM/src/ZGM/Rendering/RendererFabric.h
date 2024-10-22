#pragma once


// Fabric Layer           |
// Implemenatation Layer  |
// Abstaction Layer       V



// Subclasses with Implemenation

// I. OpenGL
#ifdef OPENGL_API
// 1. Renderer
#include "ZGM/Rendering/RenderAPI/OpenGLRenderer.h"

// 2. Geometry
#include "ZGM/Rendering/RenderAPI/OpenGLRenderAPI/OGLVertexArray.h"
#include "ZGM/Rendering/RenderAPI/OpenGLRenderAPI/OGLVertexBuffer.h"
#include "ZGM/Rendering/RenderAPI/OpenGLRenderAPI/OGLVertexBufferLayout.h"
#include "ZGM/Rendering/RenderAPI/OpenGLRenderAPI/OGLIndexBuffer.h"

// 3. Shader
#include "ZGM/Rendering/RenderAPI/OpenGLRenderAPI/OGLShader.h"
#endif



namespace Render {
	class RendererFabric {
	public:
#ifdef OPENGL_API
		static Renderer* CreateRenderer() {
			return new OGLRenderer();
		}
		
		static RenderCommand* CreateRenderCommand() {
			return new OGLRenderCommand();
		}
#endif
	};

	class GeometryFabric {
	public:
#ifdef OPENGL_API
		static VertexArray* CreateVertexArray() {
			return new OGLVertexArray();
		}

		static VertexBuffer* CreateVertexBuffer(const Vertex* vertexMassive, unsigned int count) {
			return new OGLVertexBuffer(vertexMassive, count);
		}

		static VertexBufferLayout* CreateVertexBufferLayout() {
			return new OGLVertexBufferLayout();
		}

		static IndexBuffer* CreateIndexBuffer(const unsigned int* indexMassive, unsigned int count) {
			return new OGLIndexBuffer(indexMassive, count);
		}
#endif
	};

	class ShaderFabric {
	public:
#ifdef OPENGL_API
		static Shader* CreateShader(std::string vertexShaderFilepath, std::string fragmentShaderFilepath) {
			return new OGLShader(vertexShaderFilepath, fragmentShaderFilepath);
		}
#endif
	};
}
