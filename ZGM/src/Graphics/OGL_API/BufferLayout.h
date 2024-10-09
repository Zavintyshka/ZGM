#pragma once
#include "ZGM/Core.h"
#include "General.h"

struct BufferElement {
	unsigned int count;
	GLenum type;
	GLboolean normalized;
	unsigned int strideCount;
};


class ZGM_API BufferLayout {
private:
	std::vector<BufferElement> bufferLayoutList;
public:
	void Push(GLenum type, unsigned int count, unsigned int strideCount);
	const std::vector<BufferElement>* GetElements() const;
};

