#include "zgmpch.h"

#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const float* data, int count)
	: m_data(data), m_size(count * sizeof(float))
{
	GLCall(glGenBuffers(1, &m_objectID));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_objectID));
}

void VertexBuffer::Init() const
{
	if (!m_data)
		GLCall(glBufferData(GL_ARRAY_BUFFER, m_size, nullptr, GL_DYNAMIC_DRAW));
	else
		GLCall(glBufferData(GL_ARRAY_BUFFER, m_size, m_data, GL_STATIC_DRAW));
}

unsigned int VertexBuffer::GetObjectID() const
{
	return 0;
}
