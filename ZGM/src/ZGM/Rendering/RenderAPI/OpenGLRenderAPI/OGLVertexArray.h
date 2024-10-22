#pragma once
#include "ZGM/Core.h"
#include "OGLCore.h"
#include "OGLVertexBuffer.h"
#include "OGLVertexBufferLayout.h"
#include "ZGM/Rendering/VertexArray.h"


namespace Render {
	class ZGM_API OGLVertexArray: public VertexArray {
	public:
		OGLVertexArray();
		~OGLVertexArray();

		void Bind() const override;
		void Unbind() const override;

		void AddBuffer(const VertexBuffer&, const VertexBufferLayout&) const override;
	};
}
