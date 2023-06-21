//
// Created by krist on 18. 4. 2023.
//
#include <iostream>
#include <memory>
#include <format>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#ifndef DUNNO_LOG_H
#define DUNNO_LOG_H


namespace Dunno {

    class Log
    {
    public:

        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; }

    public:
        static std::shared_ptr<spdlog::logger> s_coreLogger;
    };

} // Dunno

#define LOG_ERROR(...) ::Dunno::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_INFO(...) ::Dunno::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) ::Dunno::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Dunno::Log::GetCoreLogger()->critical(__VA_ARGS__)


#endif //DUNNO_LOG_H
