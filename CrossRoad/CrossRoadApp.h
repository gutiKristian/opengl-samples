//
// Created by krist on 26. 6. 2023.
//

#ifndef OPENGL_SAMPLES_CROSSROADAPP_H
#define OPENGL_SAMPLES_CROSSROADAPP_H


#include "core/Application.h"


class CrossRoadApp : public Dunno::Application
{
    std::array<float, 6> mSquareData = {-1.0f, }
public:

    CrossRoadApp(std::string &&name, int &&width, int &&height) : Dunno::Application(name, width, height)
    {
        LOG_INFO("Cross Road");
        // Add layer
    }
};


#endif //OPENGL_SAMPLES_CROSSROADAPP_H
