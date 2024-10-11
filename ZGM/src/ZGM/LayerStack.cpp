#include "zgmpch.h"
#include "LayerStack.h"

ZGM::LayerStack::LayerStack()
	: m_last_overlay_index(0)
{
	m_layerStack.reserve(2);

}

ZGM::LayerStack::~LayerStack()
{
	ZGM_CORE_INFO("Layers was deleted");
	m_layerStack.clear();
}

void ZGM::LayerStack::InsertLayer(const char* layerName, bool isOverlayLayer)
{
	if (isOverlayLayer) {
		m_layerStack.emplace_back(layerName, isOverlayLayer);
	}
	else {
		m_layerStack.emplace(m_layerStack.begin() + m_last_overlay_index, layerName, isOverlayLayer);
		m_last_overlay_index++;
	}

	ZGM_CLIENT_INFO("User Layer {0} initialized", layerName);
}

std::vector<ZGM::Layer>::iterator ZGM::LayerStack::Begin()
{
	return m_layerStack.begin();
}


std::vector<ZGM::Layer>::iterator ZGM::LayerStack::End()
{
	return m_layerStack.end();
}
