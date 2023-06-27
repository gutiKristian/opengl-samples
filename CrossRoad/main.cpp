//
// Created by krist on 26. 6. 2023.
//
#include <memory>

#include "core/Application.h"
#include "core/Log.h"
#include "CrossRoadLayer.h"

int main()
{
    using namespace Dunno;
    Log::Init();

    std::unique_ptr<Application> app = std::make_unique<Application>("Crossy road",
                                                                     800, 600,
                                                                     new CrossRoadLayer());
    app->Run();


    return 0;
}