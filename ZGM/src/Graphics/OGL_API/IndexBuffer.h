#pragma once
#include "ZGM/Core.h"
#include "General.h"

class ZGM_API IndexBuffer {
private:
	unsigned int m_objectID;
	unsigned int m_count;
	
public:
	IndexBuffer(const unsigned int* data, unsigned int count);

	void Bind() const;
	void Unbind() const;
	unsigned int GetObjectID() const;
	unsigned int GetCount() const;
};