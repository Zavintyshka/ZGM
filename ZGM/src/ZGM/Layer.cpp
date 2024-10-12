#include "zgmpch.h"
#include "Layer.h"

void ZGM::Layer::OnUpdate()
{

}

void ZGM::Layer::OnEvent(Event& event)
{
	ZGM_CLIENT_INFO("{0} handled by {1} layer", event.ToString(), GetName());
}

const char* ZGM::Layer::GetName() const
{
	return m_name;
}

bool ZGM::Layer::isOverlay() const
{
	return m_isOverlay;
}

ZGM::Layer::Layer(const char* name, bool isOverlay)
	: m_name(name), m_isOverlay(isOverlay) {}

ZGM::Layer::~Layer()
{

}

 