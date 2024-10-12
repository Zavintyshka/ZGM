#pragma once
#include "ZGM/Core.h"
#include "Logger.h"
#include "Events/Event.h"

namespace ZGM {
	class ZGM_API Layer {
	private:
		const char* m_name;
		bool m_isOverlay;
	public:
		Layer(const char* name, bool isOverlay);
		virtual ~Layer() = 0;
		virtual void OnUpdate();
		virtual void OnEvent(Event& event);
		virtual void OnRender();
		const char* GetName() const;
		bool isOverlay() const;
	};
}