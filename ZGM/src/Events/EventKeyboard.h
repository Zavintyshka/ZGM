#include "zgmpch.h"
#include "Event.h"

namespace ZGM {
	class KeyClickedEvent : public Event {
	private:
		int m_keyCode;
	public:
		KeyClickedEvent(int keyCode)
			: m_keyCode(keyCode) {}
	protected:
		std::string ToString() const {
			std::stringstream message;
			message << "(" << GetName() << " Key Code: " << m_keyCode << ")";
			return message.str();
		}

		EVENT_SUBCLASS_TYPE_DERERM(KeyClicked);
		EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryKeyboard);
	};


	class KeyPressedEvent : public Event {
		private:
			int m_keyCode, m_pressedCount;
		public:
			KeyPressedEvent(int keyCode, int pressedCount)
				: m_keyCode(keyCode), m_pressedCount(pressedCount) {}
		protected:
			std::string ToString() const {
				std::stringstream message;
				message << "(" << GetName() << " Key Code: " << m_keyCode << ", Count: " << m_pressedCount << ")";
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
		protected:
			std::string ToString() const {
				std::stringstream message;
				message << "(" << GetName() << " Key Code: " << m_keyCode << ")";
				return message.str();
			}

			EVENT_SUBCLASS_TYPE_DERERM(KeyReleased);
			EVENT_SUBCLASS_CATEGORY_DETERM(EventCategoryInput | EventCategoryKeyboard);
	};

}