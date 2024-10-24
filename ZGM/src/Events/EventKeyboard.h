#pragma once
#include "zgmpch.h"
#include "Event.h"

namespace ZGM {
	class KeyPressedEvent : public Event {
		private:
			int m_keyCode;
			bool m_isRepeated;

		public:
			KeyPressedEvent(int keyCode, bool isRepeated)
				: m_keyCode(keyCode), m_isRepeated(isRepeated) {}

			inline int GetKeyCode() const { return m_keyCode; };

			std::string ToString() const {
				std::stringstream message;
				const char* buttonState = m_isRepeated ? "Holding" : "Single Click";
				message << "Event: " << GetName() << " Key Code: " << m_keyCode << ", State: " << buttonState;
				return message.str();
			}

			EVENT_SUBCLASS_TYPE_DERERM(KeyPressed);
			EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryKeyboard);
	};

	class KeyReleasedEvent : public Event {
		private:
			int m_keyCode;
		public:
			KeyReleasedEvent(int keyCode)
				: m_keyCode(keyCode) {}

			inline int GetKeyCode() const { return m_keyCode; };

			std::string ToString() const {
				std::stringstream message;
				message << "Event: " << GetName() << " Key Code: " << m_keyCode;
				return message.str();
			}

			EVENT_SUBCLASS_TYPE_DERERM(KeyReleased);
			EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryKeyboard);
	};

}