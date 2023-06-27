//
// Created by krist on 23. 4. 2023.
//



#ifndef DUNNO_APPLICATION_H
#define DUNNO_APPLICATION_H

#include <memory>

#include "Window.h"
#include "Event.h"
#include "Layer.h"

namespace Dunno
{
    class Application
    {

    public:
        Application(std::string &&name, int width, int height, Layer* layer);
        ~Application();

        void Run();
        void OnEvent(Event &e); // Binds to window callback
        void OnClose();
        void OnResize(int, int);

    private:
        bool mIsRunning = false;
        std::unique_ptr<Window> pWindow;
        std::unique_ptr<Layer> pLayer;
    };

} // Dunno

#endif //DUNNO_APPLICATION_H
