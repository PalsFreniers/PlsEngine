//
// Created by tidian on 20/09/22.
//

#ifndef PLSENGINE_EVENT_H
#define PLSENGINE_EVENT_H

#include "../Core.h"

#include <string>
#include <functional>

namespace PlsEngine {
    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyBoard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } \
                                    virtual EventType GetEventType() const override { return GetStaticType(); } \
                                    virtual const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Event {
        friend class EventDispacher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const {return GetName();}

        inline bool IsInCategrory(EventCategory category) {
            return GetCategoryFlags() & category;
        }
    protected:
        bool m_Handled = false;
    };

    class EventDispacher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispacher(Event& e) : m_Event(e) {}

        template<typename T>
        bool Dispach(EventFn<T> f) {
            if (m_Event.GetEventType() == T::GetStaticType()) {
                m_Event.m_Handled = f(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };
    
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
#endif //PLSENGINE_EVENT_H
