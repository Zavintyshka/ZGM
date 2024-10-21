#pragma once
#include "ZGM/Core.h"
#include "OGLCore.h"
#include "ZGM/Rendering/IndexBuffer.h"

namespace Render {
	class ZGM_API OGLIndexBuffer: public IndexBuffer {
	public:
		OGLIndexBuffer(const unsigned int* indexMassive, unsigned int count);
		~OGLIndexBuffer();

		void Bind() const override;
		void Unbind() const override;
	};
}
