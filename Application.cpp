//
// Created by krist on 23. 4. 2023.
//

#include "Application.h"

namespace GL
{

    Application::Application(std::string title, int width, int height)
    {
        p_window = std::make_unique<Window>(title, width, height);
        // Binding to window callback
        p_window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
    }

    Application::~Application() = default;

    void Application::Run()
    {
        while(m_isRunning)
        {
            // Do stuff
            p_window->OnUpdate();
        }
    }

    void Application::OnEvent(Event &e)
    {
        // Trying out different options...instead of OnClose accepting e as other callbacks we use dynamic_cast
        if (dynamic_cast<WindowCloseEvent*>(&e))
        {
            OnClose();
        }
//        EventDispatcher::dispatch<WindowCloseEvent>([&](Event &event){}, e);
    }

    void Application::OnClose()
    {
        m_isRunning = false;
        // window destroyed in destructor
    }

} // GL