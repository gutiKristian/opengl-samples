//
// Created by krist on 22. 4. 2023.
#include <string>
#include <utility>
#include <functional>
#include "GLFW/glfw3.h"
#include "Event.h"

#ifndef DUNNO_WINDOW_H
#define DUNNO_WINDOW_H

namespace Dunno
{

    class Window
    {
        using EventCallback = std::function<void(Event&)>;
    public:
        Window(std::string title, int width, int height);
        ~Window();

        void OnUpdate();
        void SetEventCallback(const EventCallback& callback);

    private:
        void Initialize();

        struct WindowData
        {
            std::string title;
            int height;
            int width;
            EventCallback callback;
        };

        GLFWwindow* m_window;
        bool m_shouldClose = false;
        WindowData m_data;

    };

}


#endif //DUNNO_WINDOW_H
