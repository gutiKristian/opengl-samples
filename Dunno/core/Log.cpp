//
// Created by krist on 18. 4. 2023.
//

#include "Log.h"

namespace Dunno
{

    std::shared_ptr<spdlog::logger> Log::s_coreLogger;

    void Log::Init()
    {
        // Setting pattern
        // Timestamp: Message in color of it's severity
        spdlog::set_pattern("%^[%T]: %v%$");
        s_coreLogger = spdlog::stdout_color_mt("Dunno");
        s_coreLogger->set_level(spdlog::level::trace);
    }

} // Dunno