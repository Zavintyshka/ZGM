#include "zgmpch.h"
#include "OpenGLRenderer.h"

namespace Render {
	OGLRenderer::SceneData* OGLRenderer::m_sceneData = new OGLRenderer::SceneData;


	void OGLRenderer::DrawIndexed()
	{
		GLCall(glDrawElements(GL_TRIANGLES, m_sceneData->indexCount, GL_UNSIGNED_INT, nullptr));
	}

	void OGLRenderer::BeginScene(Camera& camera) {
		m_sceneData->vpMatrix = camera.GetVPMatrix();
	}

	void OGLRenderer::EndScene() {

	}

	void OGLRenderer::Submit(Shader& shader, VertexArray& vertexArray, unsigned int indexCount) {
		m_sceneData->indexCount = indexCount;

		shader.Bind();
		vertexArray.Bind();
		shader.SetUniformMat4f("u_VP", m_sceneData->vpMatrix); 
		glm::mat4 modelMatrix = glm::mat4(1.0f);
		shader.SetUniformMat4f("u_Model", modelMatrix);
		DrawIndexed();
	}

}


