#include "Event.h"

namespace ZGM {
	class MouseMovedEvent : public Event {
	private:
		int m_xPos, m_yPos;
	public:
		MouseMovedEvent(int xPos, int yPos)
			: m_xPos(xPos), m_yPos(yPos) {}

		std::string ToString() const {
			std::stringstream message;
			message << "(" << GetName() << " [" << m_xPos << ", " << m_yPos << "])";
			return message.str();
		}

		EVENT_SUBCLASS_TYPE_DERERM(MouseMoved);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};


	class MouseScrolledEvent : public Event {
	private:
		int m_xPos, m_yPos;
		bool m_direction;
	public:
		MouseScrolledEvent(int xPos, int yPos, bool direction)
			: m_xPos(xPos), m_yPos(yPos), m_direction(direction) {}

		std::string ToString() const {
			std::stringstream message;
			const char* directionStr = m_direction ? "Up" : "Down";
			message << "(" << GetName() << " [" << m_xPos << ", " << m_yPos << "] -- " << "Direction: " << directionStr << ")";
			return message.str();
		}

		EVENT_SUBCLASS_TYPE_DERERM(MouseScrolled);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};

	class MouseButtonClickedEvent : public Event {
	private:
		int m_xPos, m_yPos, m_keyCode;
	public:
		MouseButtonClickedEvent(int xPos, int yPos, int key_Code)
			: m_xPos(xPos), m_yPos(yPos), m_keyCode(key_Code) {}

		std::string ToString() const {
			std::stringstream message;
			message << "(" << GetName() << " [" << m_xPos << ", " << m_yPos << "] -- " << "Key Code: " << m_keyCode << ")";
			return message.str();
		}

		EVENT_SUBCLASS_TYPE_DERERM(MouseScrolled);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};

	class MouseButtonPressedEvent : public Event {
	private:
		int m_xPos, m_yPos, m_keyCode;
	public:
		MouseButtonPressedEvent(int xPos, int yPos, int key_Code)
			: m_xPos(xPos), m_yPos(yPos), m_keyCode(key_Code) {}

		std::string ToString() const {
			std::stringstream message;
			message << "(" << GetName() << " [" << m_xPos << ", " << m_yPos << "] -- " << "Key Code: " << m_keyCode << ")";
			return message.str();
		}

		EVENT_SUBCLASS_TYPE_DERERM(MouseScrolled);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};

	class MouseButtonReleasedEvent : public Event {
	private:
		int m_xPos, m_yPos, m_keyCode;
	public:
		MouseButtonReleasedEvent(int xPos, int yPos, int key_Code)
			: m_xPos(xPos), m_yPos(yPos), m_keyCode(key_Code) {}

		std::string ToString() const {
			std::stringstream message;
			message << "(" << GetName() << " [" << m_xPos << ", " << m_yPos << "] -- " << "Key Code: " << m_keyCode << ")";
			return message.str();
		}

		EVENT_SUBCLASS_TYPE_DERERM(MouseScrolled);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryMouse);
	};

}