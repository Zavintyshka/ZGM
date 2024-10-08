#pragma once
#include "ZGM/Core.h"

#define BIT_MASK(x) (1<<x)

#define EVENT_SUBCLASS_TYPE_DERERM(event_type)\
inline static ZGM::EventType GetStaticEventType()\
	{ return ZGM::EventType::event_type; }\
inline virtual ZGM::EventType GetEventType() const\
	{ return GetStaticEventType(); }\
inline virtual const char* GetName() const\
	{ return #event_type; }

#define EVENT_SUBCLASS_CATEGORY_DETERM(category) inline virtual int GetCategoryFlag() const override\
	{ return category; }


namespace ZGM {
	enum EventType {
		NoneEventType = 0,

		MouseMoved,
		MouseScrolled,
		MouseButtonClicked,
		MouseButtonPressed,
		MouseButtonReleased,

		KeyClicked,
		KeyPressed,
		KeyReleased,

		WindowResize,
		WindowClose,
	};

	enum EventCategory {
		NoneEventCategory = BIT_MASK(0),
		EventCategoryInput = BIT_MASK(1),
		EventCategoryMouse = BIT_MASK(2),
		EventCategoryKeyboard = BIT_MASK(3),
		EventCategoryApplication = BIT_MASK(4),
	};

	class Event {
	protected:
		bool m_isEventHandled = false;
	public:
		inline bool IsEventInCateory(EventCategory category) const {
			return GetCategoryFlag() & category;
		};
		inline virtual EventType GetEventType() const = 0;
		inline virtual const char* GetName() const = 0;
		inline virtual int GetCategoryFlag() const = 0;
		virtual std::string ToString() const { return GetName(); };
	};


	class DispatchEvent {
	private:
		ZGM::Event& m_eventObj;
		template <typename T>
		using EventFN = std::function<bool(T&)>;
	public:
		DispatchEvent(Event& eventObj)
			: m_eventObj(eventObj)
		{};

		template <typename T>
		bool Dispatch(EventFN<T> eventFN) {
			if (m_eventObj.GetEventType() == T::GetStaticType()) {
				m_eventObj.m_isEventHandled = func(*(T*)&m_eventObj);
				return true;
			}
			return false;
		}

	};
}

std::ostream& operator<<(std::ostream& os, const ZGM::Event& eventObj) {
	os << eventObj.ToString();
	return os;
}

