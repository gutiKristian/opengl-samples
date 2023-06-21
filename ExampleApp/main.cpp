//
// Created by krist on 21. 6. 2023.
//
#include <iostream>

#include "ExampleApp.h"

int main()
{
    std::unique_ptr<ExampleApp> app = std::make_unique<ExampleApp>("Example App", 1920, 1080);
    app->Run();
    return EXIT_SUCCESS;
}