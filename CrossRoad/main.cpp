//
// Created by krist on 26. 6. 2023.
//
#include <memory>

#include "core/Log.h"
#include "CrossRoadApp.h"

int main()
{
    Dunno::Log::Init();

    std::unique_ptr<CrossRoadApp> app = std::make_unique<CrossRoadApp>("Crossy road", 800, 600);
    app->Run();

    return 0;
}