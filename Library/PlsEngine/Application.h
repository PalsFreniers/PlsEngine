//
// Created by tidian on 18/09/22.
//

#ifndef PLSENGINE_APPLICATION_H
#define PLSENGINE_APPLICATION_H

#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
#include "Window.h"

namespace PlsEngine {

    class Application {
    private:
        bool m_Running = true;
        std::unique_ptr<Window> m_Window;
    private:
        bool OnWindowClose(WindowCloseEvent& e);
    public:
        Application();
        virtual ~Application();

        void Run();
        
        void OnEvent(Event& e);
    };

    //to be defined in client
    Application* CreateApplication();

} // PlsEngine

#endif //PLSENGINE_APPLICATION_H
