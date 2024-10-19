#pragma once
#include "ZGM/Core.h"
#include "OGLCore.h"

namespace Render {
	class ZGM_API VertexBuffer {
	private:
		unsigned int m_objectID;
		float* m_data;
		int m_size;
	public:
		VertexBuffer(float* data, int count);

		void Bind() const;
		void Init() const;
		unsigned int GetObjectID() const;
	};
}
