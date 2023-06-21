//
// Created by krist on 29. 4. 2023.
//

#ifndef DUNNO_EXAMPLEAPP_H
#define DUNNO_EXAMPLEAPP_H

#include "core/Application.h"

class ExampleApp : public Dunno::Application
{
public:
    ExampleApp(const std::string &&name, int &&width, int &&height) : Dunno::Application(name, width, height) {}
};


#endif //DUNNO_EXAMPLEAPP_H
