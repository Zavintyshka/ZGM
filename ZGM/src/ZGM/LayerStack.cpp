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

	for (auto it = Begin(); it != End(); it++) {
		delete (*it);
	}

	m_layerStack.clear();
}

void ZGM::LayerStack::InsertLayer(Layer* layer)
{
	if ((*layer).isOverlay()) {
		m_layerStack.push_back(layer);
	}
	else {
		m_layerStack.insert(m_layerStack.begin() + m_last_overlay_index, layer);
		m_last_overlay_index++;
	}

	ZGM_CLIENT_INFO("User Layer {0} initialized", (*layer).GetName());
}

std::vector<ZGM::Layer*>::iterator ZGM::LayerStack::Begin()
{
	return m_layerStack.begin();
}


std::vector<ZGM::Layer*>::iterator ZGM::LayerStack::End()
{
	return m_layerStack.end();
}
