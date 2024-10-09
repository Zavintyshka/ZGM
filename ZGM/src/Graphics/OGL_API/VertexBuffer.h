#pragma once
#include "ZGM/Core.h"
#include "General.h"

class ZGM_API VertexBuffer {
private:
	unsigned int m_objectID;
	const float* m_data;
	int m_size;
public:
	VertexBuffer(const float* data, int size);

	void Bind() const;
	void Init() const;
	unsigned int GetObjectID() const;
};