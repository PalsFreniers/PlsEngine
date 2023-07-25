//
// Created by tidian on 18/09/22.
//

#include "Log.h"

namespace PlsEngine {

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init() {
        spdlog::set_pattern("[%n] %H:%M:%S -> %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("PLSENGINE");
        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger = spdlog::stdout_color_mt("PLSAPPLICATION");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
} // PlsEngine
