//
// Created by krist on 29. 4. 2023.
//

#ifndef DUNNO_LAYER_H
#define DUNNO_LAYER_H

#include "Event.h"

namespace Dunno
{
    class Layer
    {
    public:
        virtual void OnAttach() {};
        virtual void OnUpdate() {};
        virtual void OnEvent(Event&) {};
        virtual void OnDetach() {};
        virtual void OnImGuiRender() {};


        virtual ~Layer() = default;
    };

}
#endif //DUNNO_LAYER_H
