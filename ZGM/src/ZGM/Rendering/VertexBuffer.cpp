#include "zgmpch.h"
#include "VertexBuffer.h"

namespace Render {
	VertexBuffer::VertexBuffer(const Vertex* vertexMassive, unsigned int count)
		: m_vertexBuffer(vertexMassive), m_vertexBufferSize(sizeof(Vertex) * count), m_vertexBufferID(999) {}

	VertexBuffer::~VertexBuffer()
	{
	}

	unsigned int VertexBuffer::GetObjectID() const{
		return m_vertexBufferID;
	}
}


