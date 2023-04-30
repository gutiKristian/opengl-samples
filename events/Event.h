//
// Created by krist on 26. 4. 2023.
//

#ifndef DUNNO_EVENT_H
#define DUNNO_EVENT_H

#define GET_STATIC_TYPE(x) static EventType GetStaticType() { return EventType::x; }
#define GET_DYNAMIC_TYPE EventType GetDynamicType() { return GetStaticType(); }

#include <string>
#include <sstream>

#include "../core/Log.h"

namespace GL
{
    enum class EventType
    {
        None,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    struct Event
    {
        GET_STATIC_TYPE(None);
        GET_DYNAMIC_TYPE;
        virtual std::string GetName() const = 0;

        bool m_isHandled = false;
    };

    struct EventDispatcher
    {
        template<class T, typename F>
        static void dispatch(const F& fun, Event& event)
        {
            static_assert(std::is_base_of<Event, T>::value, "Only events are dispatched!");

            if (event.m_isHandled)
                return;

            if (T::GetStaticType() == event.GetDynamicType())
            {
                fun(event);
                event.m_isHandled = true;
                LOG_INFO(event.GetName());
            }

        }
    };

    /*
     * WINDOW EVENTS
     */
    struct WindowCloseEvent : public Event
    {
        GET_STATIC_TYPE(WindowClose);
        GET_DYNAMIC_TYPE;

        std::string GetName() const override
        {
            std::stringstream s;
            s << "[EVENT]: WindowClose";
            return s.str();
        }
    };

    /*
     * KEYCODE EVENTS
     */
    struct KeyCodeEvent : public Event
    {
    protected:
        int m_keyCode;
        explicit KeyCodeEvent(int keyCode): m_keyCode(keyCode) {}
    };

    struct KeyPressedEvent : public KeyCodeEvent
    {
        KeyPressedEvent(int keyCode, bool isPressed) : KeyCodeEvent(keyCode), m_isPressed(isPressed) {}
        GET_STATIC_TYPE(KeyPressed);
        GET_DYNAMIC_TYPE;

        std::string GetName() const override
        {
            std::stringstream s;
            s << "[EVENT]: KeyPressed: "  << m_keyCode << " | IsPressed: " << (m_isPressed ? "True" : "False");
            return s.str();
        }

    private:
        bool m_isPressed;
    };

    struct KeyReleasedEvent : public KeyCodeEvent
    {
        explicit KeyReleasedEvent(int keyCode) : KeyCodeEvent(keyCode) {}
        GET_STATIC_TYPE(KeyReleased);
        GET_DYNAMIC_TYPE;

        std::string GetName() const override
        {
            std::stringstream s;
            s << "[EVENT]: KeyReleasedEvent: "  << m_keyCode;
            return s.str();
        }

    };

    /*
     * MOUSE EVENTS
     */




}

#endif //DUNNO_EVENT_H
