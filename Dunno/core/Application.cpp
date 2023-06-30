//
// Created by krist on 23. 4. 2023.
//

#include "Application.h"

namespace Dunno
{
    Application::Application(std::string &&name, int width, int height, Layer *layer) : pWindow(std::make_unique<Window>(name, width, height)),
        pLayer(std::unique_ptr<Layer>(layer)), mImGuiLayer(pWindow->GetNativeWindow()) //  this is not very nice but will do :))
    {
        // Binding to window callback
        pWindow->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
        pLayer->OnAttach();
        mImGuiLayer.OnAttach();
    }

    void Application::Run()
    {
        mIsRunning = true;

        while(mIsRunning)
        {
            // Do stuff
            pLayer->OnUpdate();

            mImGuiLayer.Begin();
            pLayer->OnImGuiRender();
            mImGuiLayer.End();

            pWindow->OnUpdate();
        }
    }

    void Application::OnEvent(Event &e)
    {

        // Trying out different options...instead of OnClose accepting e as other callbacks we use dynamic_cast
        if (dynamic_cast<WindowCloseEvent*>(&e))
        {
            OnClose();
        }

        // using dispatcher
        EventDispatcher::Dispatch<WindowResizeEvent>([&](WindowResizeEvent& ev)
        {
            auto [width, height] = pWindow->GetResolution();
            OnResize(width, height);
        },e);

        if (e.IsHandled)
        {
            return;
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

    void Application::OnResize(int width, int height)
    {
//        pLayer->OnResize(width, height);
    }


} // Dunno