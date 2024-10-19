#include "zgmpch.h"
#include "OpenGLRenderer.h"

namespace Render {
	void OGLRenderer::DrawElements()
	{
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
	}
}


