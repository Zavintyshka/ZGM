#include "zgmpch.h"
#include "OpenGLRenderer.h"

namespace Render {
	void OGLRenderer::DrawIndexed()
	{
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
	}

	void OGLRenderer::BeginScene() {
		
	}

	void OGLRenderer::EndScene() {

	}

	void OGLRenderer::Submit() {
		DrawIndexed();
	}

}


