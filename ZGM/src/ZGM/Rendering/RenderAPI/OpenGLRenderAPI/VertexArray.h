#pragma once
#include "ZGM/Core.h"
#include "OGLCore.h"
#include "OGLVertexBuffer.h"
#include "BufferLayout.h"

namespace Render {
	class ZGM_API VertexArray {
	private:
		unsigned int m_objectID;
	public:
		VertexArray();
		~VertexArray();

		void BindVertexArray() const;
		void UnbindVertexArray() const;

		void AddBuffer(const OGLVertexBuffer& vertexBuffer, const BufferLayout& bufferLayout) const;
	};
}
