#pragma once
#include "zgmpch.h"
#include "ZGM/Layer.h"
#include "ZGM/Core.h"

namespace ZGM {
	class ZGM_API LayerStack {
	private:
		std::vector<Layer> m_layerStack;
		int m_last_overlay_index;
	public:
		LayerStack();
		~LayerStack();

		void InsertLayer(const char* layerName, bool isOverlayLayer);

		std::vector<Layer>::iterator Begin();
		std::vector<Layer>::iterator End();
	};
}


