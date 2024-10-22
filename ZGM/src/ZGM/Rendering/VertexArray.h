#pragma once
#include "ZGM/Core.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Render {
	class ZGM_API VertexArray {
	protected:
		unsigned int m_vertexArrayID;
	public:
		VertexArray(): m_vertexArrayID(999) {};
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& vertexBufferLayout) const = 0;
	};
}