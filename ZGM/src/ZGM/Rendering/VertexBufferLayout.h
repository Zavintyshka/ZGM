#pragma once
#include "zgmpch.h"
#include "ZGM/Core.h"

namespace Render {
	struct LayoutElement {
		unsigned int componentType;
		unsigned int componentCount;
		bool normalized;
		unsigned int strideComponentCount;
	};

	class ZGM_API VertexBufferLayout {
	protected:
		std::vector<LayoutElement> vertexBufferLayout;
	public:
		virtual void Push(unsigned int componentType, unsigned int componentCount, bool normalized, unsigned int strideComponentCount) {
			vertexBufferLayout.push_back({ componentType, componentCount, normalized, strideComponentCount });
		};
		inline const std::vector<LayoutElement>* GetLayout() const { return &vertexBufferLayout; };
	};
}