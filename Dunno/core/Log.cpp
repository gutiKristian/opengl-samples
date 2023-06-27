//
// Created by krist on 18. 4. 2023.
//

#include "Log.h"

namespace Dunno
{

    std::shared_ptr<spdlog::logger> Log::sCoreLogger = nullptr;

    void Log::Init()
    {
        if (Log::sCoreLogger)
            return;

        // Setting pattern
        // Timestamp: Message in color of it's severity
        spdlog::set_pattern("%^[%T]: %v%$");
        sCoreLogger = spdlog::stdout_color_mt("Dunno");
        sCoreLogger->set_level(spdlog::level::trace);
    }

} // Dunno