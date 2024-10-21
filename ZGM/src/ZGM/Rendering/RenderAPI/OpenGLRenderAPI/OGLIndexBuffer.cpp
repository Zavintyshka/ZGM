#include "zgmpch.h"
#include "OGLIndexBuffer.h"

namespace Render {
	OGLIndexBuffer::OGLIndexBuffer(const unsigned int* indexMassive, unsigned int count)
		: IndexBuffer(indexMassive, count)
	{
		GLCall(glGenBuffers(1, &m_indexBufferID));
		Bind();
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferSize, m_indexBuffer, GL_STATIC_DRAW));
	}

	OGLIndexBuffer::~OGLIndexBuffer()
	{
		GLCall(glDeleteBuffers(1, &m_indexBufferID));
	}

	void OGLIndexBuffer::Bind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID));
	}

	void OGLIndexBuffer::Unbind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}

