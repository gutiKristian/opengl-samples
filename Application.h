//
// Created by krist on 23. 4. 2023.
//



#ifndef DUNNO_APPLICATION_H
#define DUNNO_APPLICATION_H

#include <memory>

#include "core/Window.h"
#include "events/Event.h"

namespace GL
{

    class Application
    {
    public:
        Application(std::string name, int width, int height);
        ~Application();

        void Run();
        void OnEvent(Event &e); // Binds to window callback
        void OnClose();

    private:
        std::unique_ptr<Window> p_window;
        bool m_isRunning;
//        std::unique_ptr<Layer>
    };

} // GL

#endif //DUNNO_APPLICATION_H
