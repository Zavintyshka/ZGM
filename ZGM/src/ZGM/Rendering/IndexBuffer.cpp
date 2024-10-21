#include "zgmpch.h"
#include "IndexBuffer.h"

namespace Render {
	IndexBuffer::IndexBuffer(const unsigned int* indexMassive, unsigned int count)
		: m_indexBufferID(999), m_indexBuffer(indexMassive), m_indexBufferCount(count), m_indexBufferSize(sizeof(unsigned int) * count) {}

	IndexBuffer::~IndexBuffer()
	{

	}

	inline unsigned int IndexBuffer::GetCount() const
	{
		return m_indexBufferCount;
	}

	inline unsigned int IndexBuffer::GetSize() const
	{
		return m_indexBufferSize;
	}
}