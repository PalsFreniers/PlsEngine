//
// Created by tidian on 20/09/22.
//

#ifndef PLSENGINE_KEYEVENT_H
#define PLSENGINE_KEYEVENT_H

#include "Event.h"

namespace PlsEngine {
    class KeyEvent : public Event {
    public:
        inline int GetKeyCode() const { return m_KeyCode;}

        EVENT_CLASS_CATEGORY(EventCategoryKeyBoard | EventCategoryInput)
    protected:
        KeyEvent(int keyCode) : m_KeyCode(keyCode) {}
        int m_KeyCode;
    };
    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}
        inline int GetRepeatCount() const {return m_RepeatCount;}
        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent : <code : " << m_KeyCode << ">,<time : " << m_RepeatCount << ">";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount;
    };

    class KeyReleaseEvent : public KeyEvent {
    public:
        KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {}
        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleaseEvent : <code : " << m_KeyCode << ">";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}

#endif //PLSENGINE_KEYEVENT_H
