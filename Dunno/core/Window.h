//
// Created by krist on 22. 4. 2023.
#ifndef DUNNO_WINDOW_H
#define DUNNO_WINDOW_H

#include <string>
#include <utility>
#include <functional>
#include <format>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Event.h"
#include "Log.h"

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
        std::tuple<int, int> GetResolution() const;
        inline GLFWwindow* GetNativeWindow() const { return m_window; }

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
