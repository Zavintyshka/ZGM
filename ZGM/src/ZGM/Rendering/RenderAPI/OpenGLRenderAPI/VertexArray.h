#pragma once
#include "ZGM/Core.h"
#include "OGLCore.h"
#include "VertexBuffer.h"
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

		void AddBuffer(const VertexBuffer& vertexBuffer, const BufferLayout& bufferLayout) const;
	};
}