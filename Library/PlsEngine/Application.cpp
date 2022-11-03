//
// Created by tidian on 18/09/22.
//

#include "Application.h"

#include "Event/ApplicationEvent.h"
#include "Log.h"

namespace PlsEngine {
    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::Run() {
        WindowResizeEvent e(1920, 1080);
        CORE_TRACE(e);
        while(true);
    }
} // PlsEngine
