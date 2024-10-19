#include "zgmpch.h"
#include "VertexBuffer.h"


namespace Render {
	VertexBuffer::VertexBuffer(float* data, int count)
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
		if (!m_data) {
			ZGM_CORE_INFO("USE DYNAMIC DRAW");
			GLCall(glBufferData(GL_ARRAY_BUFFER, m_size, nullptr, GL_DYNAMIC_DRAW));
		}
		else {
			ZGM_CORE_INFO("USE STATIC DRAW");
			GLCall(glBufferData(GL_ARRAY_BUFFER, m_size, m_data, GL_STATIC_DRAW));
		}
			
	}

	unsigned int VertexBuffer::GetObjectID() const
	{
		return 0;
	}
}

