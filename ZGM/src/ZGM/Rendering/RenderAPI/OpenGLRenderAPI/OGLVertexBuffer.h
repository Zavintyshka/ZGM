#pragma once
#include "ZGM/Core.h"
#include "OGLCore.h"
#include "ZGM/Rendering/VertexBuffer.h"

namespace Render {
	class ZGM_API OGLVertexBuffer : public VertexBuffer {
	public:
		OGLVertexBuffer(const Vertex* vertexMassive, int count);
		~OGLVertexBuffer() override;
		void Bind() const override;
		void Init() const override;
	};
}
