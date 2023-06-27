//
// Created by krist on 27. 6. 2023.
//
#include "SimpleTriangleLayer.h"
#include "core/Log.h"
#include "core/Application.h"

using namespace Dunno;

int main()
{
    Log::Init();

    LOG_INFO("Simple triangle");

    auto* app = new Application("Simple Triangle", 800, 600, new SimpleTriangleLayer());

    app->Run();

    delete app;

    return 0;
}