#pragma once
#include "ZGM/Core.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class ZGM_API Renderer {
private:
public:
	void Draw(VertexArray& vaObj, IndexBuffer& ibObj, Shader& shaderObj);
	void Clear() const;
};