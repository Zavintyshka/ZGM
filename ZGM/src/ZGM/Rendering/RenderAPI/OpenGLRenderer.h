#pragma once
#include "OpenGLRenderAPI/OGLCore.h"
#include "ZGM/Rendering/Renderer.h"

namespace Render {
	class ZGM_API OGLRenderer: public Renderer {
	private:
	public:
		void DrawElements() override;
	};
}