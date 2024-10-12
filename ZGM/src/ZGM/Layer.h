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
		void virtual OnUpdate();
		void virtual OnEvent(Event& event);
		const char* GetName() const;
		bool isOverlay() const;
	};
}