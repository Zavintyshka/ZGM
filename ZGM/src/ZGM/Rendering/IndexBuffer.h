#pragma once
#include "ZGM/Core.h"


namespace Render {
	class ZGM_API IndexBuffer {
	protected:
		unsigned int m_indexBufferID;
		const unsigned int* m_indexBuffer;
		unsigned int m_indexBufferCount;
		unsigned int m_indexBufferSize;
	public:
		IndexBuffer(const unsigned int* indexMassive, unsigned int count);
		virtual ~IndexBuffer();

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		inline unsigned int GetCount() const;
		inline unsigned int GetSize() const;
	};
}
