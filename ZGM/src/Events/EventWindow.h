#pragma once
#include "zgmpch.h"
#include "Event.h"


namespace ZGM {
	class WindowResizeEvent : public Event {
	private:
		int m_width, m_height;
	public:
		WindowResizeEvent(int width, int height)
			: m_width(width), m_height(height) {}

		std::string ToString() const {
			std::stringstream message;
			message << "Event: " << GetName() << " Resolution: (" << m_width << ", " << m_height << ")";
			return message.str();
		}

		EVENT_SUBCLASS_TYPE_DERERM(WindowResize);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryApplication);
	};


	class WindowCloseEvent : public Event {
	private:
	public:
		WindowCloseEvent()
		{}
		std::string ToString() const {
			std::stringstream message;
			message << "Event: " << GetName();
			return message.str();
		}

		EVENT_SUBCLASS_TYPE_DERERM(WindowClose);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryApplication);
	};
}
