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
        Application(std::string name = "App", int width = 800, int height = 600);
        ~Application();

        void Run();
        void OnEvent(Event &e); // Binds to window callback
        void OnClose();

    private:
        std::unique_ptr<Window> p_window;
        bool m_isRunning;
        std::unique_ptr<Layer> p_layer;

    };

} // Dunno

#endif //DUNNO_APPLICATION_H
