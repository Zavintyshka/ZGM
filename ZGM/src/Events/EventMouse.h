#pragma once
#include "Event.h"

namespace ZGM {
	class MouseMovedEvent : public Event {
	private:
		double m_xPos, m_yPos;
	public:
		MouseMovedEvent(double xPos, double yPos)
			: m_xPos(xPos), m_yPos(yPos) {}

		std::string ToString() const {
			std::stringstream message;
			message << "Event: " << GetName() << " (" << m_xPos << ", " << m_yPos << ")";
			return message.str();
		}

		inline double GetXPos() const { return m_xPos; };
		inline double GetYPos() const { return m_yPos; };

		
		EVENT_SUBCLASS_TYPE_DERERM(MouseMoved);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};


	class MouseScrolledEvent : public Event {
	private:
		const char* m_direction;
		double m_wheelY;
	public:
		MouseScrolledEvent(double yOffset)
			: m_wheelY(yOffset)
		{
			m_direction = yOffset > 0 ? "Up" : "Down";
		}

		std::string ToString() const {
			std::stringstream message;
			message << "Event: " << GetName() << " Direction: " << m_direction;
			return message.str();
		}

		inline const char* GetDirection() const {
			return m_direction;
		};

		EVENT_SUBCLASS_TYPE_DERERM(MouseScrolled);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};

	class MouseButtonPressedEvent : public Event {
	private:
		int m_keyCode;
	public:
		MouseButtonPressedEvent(int keyCode)
			: m_keyCode(keyCode) {}

		std::string ToString() const {
			std::stringstream message;
			message << "Event: " << GetName() << " Key Code: " << m_keyCode;
			return message.str();
		}

		inline int GetKeyCode() const { return m_keyCode; };

		EVENT_SUBCLASS_TYPE_DERERM(MouseButtonPressed);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};

	class MouseButtonReleasedEvent : public Event {
	private:
		int m_keyCode;
	public:
		MouseButtonReleasedEvent(int keyCode)
			: m_keyCode(keyCode) {}

		std::string ToString() const {
			std::stringstream message;
			message << "Event: " << GetName() << " Key Code: " << m_keyCode;
			return message.str();
		}

		inline int GetKeyCode() const { return m_keyCode; };

		EVENT_SUBCLASS_TYPE_DERERM(MouseButtonReleased);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};

}