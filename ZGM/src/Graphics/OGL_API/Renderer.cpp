#include "zgmpch.h"
#include "Renderer.h"

void Renderer::Draw(VertexArray& vaObj, IndexBuffer& ibObj, Shader& shaderObj)
{
	vaObj.BindVertexArray();
	ibObj.Bind();
	shaderObj.BindShader();
	GLCall(glDrawElements(GL_TRIANGLES, ibObj.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}
