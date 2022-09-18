//
// Created by tidian on 18/09/22.
//

#ifndef PLSENGINE_LOG_H
#define PLSENGINE_LOG_H

//core logger macros
#define CORE_TRACE(...) ::PlsEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...) ::PlsEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...) ::PlsEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) ::PlsEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) ::PlsEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//client logger macros
#define CLIENT_TRACE(...) ::PlsEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO(...) ::PlsEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...) ::PlsEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...) ::PlsEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_FATAL(...) ::PlsEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)


#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace PlsEngine {

    class Log {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

} // PlsEngine

#endif //PLSENGINE_LOG_H
