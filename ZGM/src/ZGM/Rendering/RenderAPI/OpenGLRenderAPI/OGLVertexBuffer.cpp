#include "zgmpch.h"
#include "OGLVertexBuffer.h"


namespace Render {
	OGLVertexBuffer::OGLVertexBuffer(const Vertex* vertexMassive, int count)
		: VertexBuffer(vertexMassive, count)
	{
		GLCall(glGenBuffers(1, &m_vertexBufferID));
	}

	OGLVertexBuffer::~OGLVertexBuffer()
	{
		GLCall(glDeleteBuffers(1, &m_vertexBufferID));
	}

	void OGLVertexBuffer::Bind() const
	{
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID));
	}

	void OGLVertexBuffer::Init() const
	{
		if (!m_vertexBuffer) {
			GLCall(glBufferData(GL_ARRAY_BUFFER, m_vertexBufferSize, nullptr, GL_DYNAMIC_DRAW));
		}
		else {
			GLCall(glBufferData(GL_ARRAY_BUFFER, m_vertexBufferSize, m_vertexBuffer, GL_STATIC_DRAW));
		}
			
	}
}

