#pragma once
#include "ZGM/Core.h"

namespace Render {
	struct Vertex {
		// Vertex size - 6 * float = 32 bytes

		// Vertex Position
		float x, y, z, w;
		// Texture Position
		float tPosX, tPoxY;

		// Vertex Color
		// --TBD--
		
	};

	class ZGM_API VertexBuffer {
	protected:
		unsigned int m_vertexBufferID;
		const Vertex* m_vertexBuffer;
		unsigned int m_vertexBufferSize;
	public:
		VertexBuffer(const Vertex* vertexMassive, unsigned int count);
		virtual ~VertexBuffer() ;
		virtual void Bind() const = 0;
		virtual void Init() const = 0;
		inline unsigned int GetObjectID() const;
	};
}