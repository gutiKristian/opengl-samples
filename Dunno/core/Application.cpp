//
// Created by krist on 23. 4. 2023.
//

#include "Application.h"

namespace Dunno
{
    Application::Application(std::string &&name, int width, int height, Layer *layer)
    {
        pWindow = std::make_unique<Window>(name, width, height);
        // Binding to window callback
        pWindow->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
        pLayer = std::unique_ptr<Layer>(layer);

        pLayer->OnAttach();
    }

    void Application::Run()
    {
        mIsRunning = true;

        while(mIsRunning)
        {
            // Do stuff
            pWindow->OnUpdate();
            pLayer->OnUpdate();
        }
    }

    void Application::OnEvent(Event &e)
    {
        // Trying out different options...instead of OnClose accepting e as other callbacks we use dynamic_cast
        if (dynamic_cast<WindowCloseEvent*>(&e))
        {
            OnClose();
        }

        pLayer->OnEvent(e);
    }

    // Called within in an event
    void Application::OnClose()
    {
        mIsRunning = false;
    }

    Application::~Application()
    {
        pLayer->OnDetach();
    }


} // Dunno