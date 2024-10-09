#include "zgmpch.h"
#include "BufferLayout.h"


void BufferLayout::Push(GLenum type, unsigned int count, unsigned int strideCount)
{
	bufferLayoutList.push_back({ count, type, false, strideCount });
}

const std::vector<BufferElement>* BufferLayout::GetElements() const
{
	return &bufferLayoutList;
}
